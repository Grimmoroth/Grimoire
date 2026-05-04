#ifndef GRIMOIRE_OPENCV_FRAME_SOURCE_HPP
#define GRIMOIRE_OPENCV_FRAME_SOURCE_HPP
#include <opencv2/videoio.hpp>
#include <optional>

#include "grimoire/interfaces/i_frame_source.hpp"

namespace grimoire::core::types
{
    struct Frame;
};

namespace grimoire::core
{

    class OpenCvFrameSource final : public interfaces::IFrameSource
    {
    public:
        explicit OpenCvFrameSource(int p_cam_index = 0);
        ~OpenCvFrameSource() override;

        [[nodiscard]] bool open() override;
        void close() override;

        [[nodiscard]] std::optional<types::Frame> next() override;
        [[nodiscard]] bool isOpen() const noexcept override;

    private:
        int _cam_index{};
        cv::VideoCapture _capture;
        std::uint64_t _frame_index{};
    };

};  // namespace grimoire::core

#endif