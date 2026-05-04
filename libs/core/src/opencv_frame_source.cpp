#include "opencv_frame_source.hpp"

#include <optional>

#include "grimoire/types/frame.hpp"
#include "opencv2/core/mat.hpp"

namespace grimoire::core
{
    OpenCvFrameSource::OpenCvFrameSource(int p_cam_index)
    : _cam_index{p_cam_index}
    {
    }

    OpenCvFrameSource::~OpenCvFrameSource() { close(); }

    void
    OpenCvFrameSource::close()
    {
        if (_capture.isOpened())
        {
            _capture.release();
        }
    }

    std::optional<types::Frame>
    OpenCvFrameSource::next()
    {
        cv::Mat mat{};
        if (mat.empty())  // TODO: Fix this line !(_capture >> mat)
        {
            return std::nullopt;
        }

        return types::Frame{
            std::move(mat), static_cast<uint32_t>(_frame_index++)};
    }

    bool
    OpenCvFrameSource::isOpen() const noexcept
    {
        return _capture.isOpened();
    }

};  // namespace grimoire::core
