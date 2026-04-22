#ifndef GRIMOIRE_INTERFACES_I_FRAME_SOURCE_HPP
#define GRIMOIRE_INTERFACES_I_FRAME_SOURCE_HPP

#include <optional>

namespace grimoire::core::types
{
    struct Frame;
}

namespace grimoire::core::interfaces
{
    class IFrameSource
    {
    public:
        virtual ~IFrameSource() = default;

        IFrameSource(const IFrameSource&) = delete;
        IFrameSource operator=(const IFrameSource&) = delete;
        IFrameSource(IFrameSource&&) = delete;
        IFrameSource& operator=(IFrameSource&&) = delete;

        [[nodiscard]] virtual bool open() = 0;
        virtual void close() = 0;

        [[nodiscard]] virtual std::optional<types::Frame> next() = 0;
        [[nodiscard]] virtual bool isOpen() const noexcept = 0;

    protected:
        IFrameSource() = default;
    };
};  // namespace grimoire::core::interfaces

#endif