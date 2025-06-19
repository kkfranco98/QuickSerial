#include "quick_serial.hpp"

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