#ifndef GRIMOIRE_TYPES_ASCII_FRAME_HPP
#define GRIMOIRE_TYPES_ASCII_FRAME_HPP

#include <cstdint>
#include <vector>
namespace grimoire::core::types
{
    struct Color
    {
        std::uint8_t r{};
        std::uint8_t g{};
        std::uint8_t b{};
    };

    struct Cell
    {
        char ch{};
        Color clr;
    };

    struct AsciiFrame
    {
        std::vector<std::vector<Cell>> cells;
        std::size_t rows{};
        std::size_t cols{};

        std::uint64_t index;

        AsciiFrame() = default;
        AsciiFrame(
            std::size_t p_rows,
            std::size_t p_cols,
            std::uint64_t p_index)
        : cells(p_rows, std::vector<Cell>(p_cols))
        , rows{p_rows}
        , cols{p_cols}
        , index{p_index}
        {
        }

        [[nodiscard]] bool
        empty() const noexcept
        {
            return rows == 0 || cols == 0;
        }

        [[nodiscard]] const Cell&
        at(std::size_t p_row, std::size_t p_col)
        {
            return cells.at(p_row).at(p_col);
        }

        [[nodiscard]] Cell&
        at(std::size_t p_row, std::size_t p_col)
        {
            return cells.at(p_row).at(p_col);
        }
    };

}  // namespace grimoire::core::types
#endif