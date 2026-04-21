#ifndef GRIMOIRE_TYPES_FRAME_HPP
#define GRIMOIRE_TYPES_FRAME_HPP

#include <chrono>
#include <opencv2/core/mat.hpp>

namespace grimoire::core::types
{

    struct Frame
    {
        cv::Mat pixels;
        int width{};
        int height{};

        std::chrono::steady_clock::time_point timestamp{};
        std::uint32_t index{};

        Frame() = default;
        explicit Frame(cv::Mat p_pixels, uint32_t p_index = 0)
        : pixels{std::move(p_pixels)}
        , width{pixels.cols}
        , height{pixels.rows}
        , timestamp(std::chrono::steady_clock::now())
        , index{p_index}
        {
        }

        [[nodiscard]] bool
        empty() const noexcept
        {
            return pixels.empty();
        }

        [[nodiscard]] bool
        valid()
        {
            return !empty() && width > 0 && height > 0;
        }
    };
};  // namespace grimoire::core::types

#endif