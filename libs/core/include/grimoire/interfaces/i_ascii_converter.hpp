#ifndef GRIMOIRE_INTERFACES_I_ASCII_CONVERTER
#define GRIMOIRE_INTERFACES_I_ASCII_CONVERTER

#include <string_view>

namespace grimoire::core::types
{
    struct AsciiFrame;
    struct Frame;
};  // namespace grimoire::core::types

namespace grimoire::core::interfaces
{

    class IAsciiConverter
    {
    public:
        virtual ~IAsciiConverter() = default;

        IAsciiConverter(const IAsciiConverter&) = delete;
        IAsciiConverter& operator=(const IAsciiConverter&) = delete;
        IAsciiConverter(IAsciiConverter&&) = delete;
        IAsciiConverter& operator=(IAsciiConverter&&) = delete;

        [[nodiscard]] virtual types::AsciiFrame convert(
            const types::Frame& p_inp) const = 0;

        [[nodiscard]] virtual std::string_view ramp()
            const noexcept = 0;

    protected:
        IAsciiConverter();
    };
};  // namespace grimoire::core::interfaces
#endif