#ifndef GRIMOIRE_INTERFACES_I_FRAME_PROCESSOR_HPP
#define GRIMOIRE_INTERFACES_I_FRAME_PROCESSOR_HPP

namespace grimoire::core::types
{
    struct Frame;
};

namespace grimoire::core::interfaces
{
    class IFrameProcessor
    {
    public:
        virtual ~IFrameProcessor() = default;

        IFrameProcessor(const IFrameProcessor&) = delete;
        IFrameProcessor& operator=(const IFrameProcessor&) = delete;
        IFrameProcessor(IFrameProcessor&&) = delete;
        IFrameProcessor& operator=(IFrameProcessor&&) = delete;

        [[nodiscard]] virtual types::Frame process(
            const types::Frame& p_frame) const = 0;

        [[nodiscard]] virtual int targetCols() const noexcept = 0;
        [[nodiscard]] virtual int targetRows() const noexcept = 0;

    protected:
        IFrameProcessor();
    };
};  // namespace grimoire::core::interfaces

#endif