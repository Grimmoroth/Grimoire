#ifndef GRIMOIRE_PIPELINE_PIPELINE_HPP
#define GRIMOIRE_PIPELINE_PIPELINE_HPP

#include <atomic>
#include <memory>

namespace grimoire::core::interfaces
{
    class IFrameSource;
    class IFrameProcessor;
    class IAsciiConverter;
    class IOutputWritter;
};  // namespace grimoire::core::interfaces

namespace grimoire::core::pipeline
{
    struct PipelineConfig
    {
        int target_fps{30};
    };

    class Pipeline
    {
    public:
        Pipeline(
            PipelineConfig p_config,
            std::unique_ptr<interfaces::IFrameSource> p_source,
            std::unique_ptr<interfaces::IFrameProcessor> p_processor,
            std::unique_ptr<interfaces::IAsciiConverter> p_converter,
            std::unique_ptr<interfaces::IOutputWritter> p_writter);

        Pipeline(const Pipeline&) = delete;
        Pipeline& operator=(const Pipeline&) = delete;
        Pipeline(Pipeline&&) = delete;
        Pipeline& operator=(Pipeline&&) = delete;

        ~Pipeline();

        [[nodiscard]] bool run();
        void stop() noexcept;
        [[nodiscard]] bool isRunning() const noexcept;

    private:
        void runLoop();
        bool openAll();
        void closeAll() noexcept;

        PipelineConfig _config;
        std::unique_ptr<interfaces::IFrameSource> _source;
        std::unique_ptr<interfaces::IFrameProcessor> _processor;
        std::unique_ptr<interfaces::IAsciiConverter> _converter;
        std::unique_ptr<interfaces::IOutputWritter> _writter;

        std::atomic<bool> _running{false};
    };
};  // namespace grimoire::core::pipeline

#endif
