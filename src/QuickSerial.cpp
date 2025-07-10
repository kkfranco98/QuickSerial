#include "QuickSerial.hpp"

void QuickSerial::set_digits_after_decimal_point(const uint32_t &digits_after_decimal_point)
{
    _digits_after_decimal_point = digits_after_decimal_point;
}

void QuickSerial::println()
{
    _used_serial.println();
}

char QuickSerial::get_end_bracket_from_start_bracket(const char &start_bracket)
{
    switch (start_bracket)
    {
    case '[':
        return ']';
        break;

    case '{':
        return '}';
        break;

    case '(':
        return ')';
        break;

    case '<':
        return '>';
        break;

    default:
        return start_bracket;
        break;
    }
}

void QuickSerial::print_this_spaces(uint32_t spaces)
{
    for (uint32_t i = 0; i < spaces; i++)
    {
        _used_serial.print(" ");
    }
}

int QuickSerial::count_digits(int n)
{
    if (n == 0)
        return 1;
    return (int)std::log10(std::abs(n)) + 1;
}