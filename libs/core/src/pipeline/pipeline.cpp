#include "grimoire/pipeline/pipeline.hpp"

#include <cassert>
#include <chrono>
#include <exception>
#include <iostream>
#include <thread>

#include "grimoire/interfaces/i_ascii_converter.hpp"
#include "grimoire/interfaces/i_frame_processor.hpp"
#include "grimoire/interfaces/i_frame_source.hpp"
#include "grimoire/interfaces/i_output_writter.hpp"
#include "grimoire/types/ascii_frame.hpp"
#include "grimoire/types/frame.hpp"

namespace grimoire::core::pipeline
{
    Pipeline::Pipeline(
        PipelineConfig p_config,
        std::unique_ptr<interfaces::IFrameSource> p_source,
        std::unique_ptr<interfaces::IFrameProcessor> p_processor,
        std::unique_ptr<interfaces::IAsciiConverter> p_converter,
        std::unique_ptr<interfaces::IOutputWritter> p_writter)
    : _config{p_config}
    , _source{std::move(p_source)}
    , _processor{std::move(p_processor)}
    , _converter{std::move(p_converter)}
    , _writter{std::move(p_writter)}
    {
        assert(
            _source != nullptr &&
            "Pipeline: source must not be null");

        assert(
            _processor != nullptr &&
            "Pipeline: processor must not be null");

        assert(
            _converter != nullptr &&
            "Pipeline: converter must not be null");

        assert(
            _writter != nullptr &&
            "Pipeline: writter must not be null");
    }

    Pipeline::~Pipeline()
    {
        stop();
        closeAll();
    }

    bool
    Pipeline::run()
    {
        if (!openAll())
        {
            closeAll();
            return false;
        }

        _running.store(true);
        runLoop();
        _running.store(false);

        closeAll();
        return true;
    }

    void
    Pipeline::stop() noexcept
    {
        _running.store(false);
    }

    bool
    Pipeline::isRunning() const noexcept
    {
        return _running.load();
    }

    bool
    Pipeline::openAll()
    {
        return _source->open() && _writter->open();
    }

    void
    Pipeline::closeAll() noexcept
    {
        try
        {
            _writter->close();
        }
        catch (const std::exception& e)
        {
            std::cerr << "Writter close error: " << e.what();
        }

        try
        {
            _source->close();
        }
        catch (const std::exception& e)
        {
            std::cerr << "source close error: " << e.what();
        }
    }

    void
    Pipeline::runLoop()
    {
        const auto frame_duration{
            std::chrono::duration<double>(1 / _config.target_fps)};

        while (_running.load())
        {
            const auto frame_start{std::chrono::steady_clock::now()};
            auto raw{_source->next()};
            if (!raw.has_value())
            {
                break;
            }

            types::Frame processed{_processor->process(*raw)};
            types::AsciiFrame ascii{_converter->convert(processed)};
            _writter->write(ascii);

            const auto elapsed{
                std::chrono::steady_clock::now() - frame_start};
            const auto remaining{frame_duration - elapsed};
            if (remaining > std::chrono::duration<double>::zero())
            {
                std::this_thread::sleep_for(remaining);
            }
        }
    }

};  // namespace grimoire::core::pipeline