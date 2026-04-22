#ifndef GRIMOIRE_INTERFACES_I_OUTPUT_WRITTTER_HPP
#define GRIMOIRE_INTERFACES_I_OUTPUT_WRITTTER_HPP

namespace grimoire::core::types
{

    struct AsciiFrame;
};

namespace grimoire::core::interfaces
{
    class IOutputWritter
    {
    public:
        virtual ~IOutputWritter() = default;

        IOutputWritter(const IOutputWritter&) = delete;
        IOutputWritter& operator=(const IOutputWritter) = delete;
        IOutputWritter(IOutputWritter&&) = delete;
        IOutputWritter& operator=(IOutputWritter&&) = delete;

        [[nodiscard]] virtual bool open() = 0;
        virtual void close() = 0;
        virtual void write(const types::AsciiFrame& p_frame) = 0;

        [[nodiscard]] virtual bool isOpen() const noexcept = 0;

    protected:
        IOutputWritter() = default;
    };
};  // namespace grimoire::core::interfaces

#endif