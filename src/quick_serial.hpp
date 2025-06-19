#pragma once

#include <Arduino.h>

class QuickSerial
{
private:
    HardwareSerial &_used_serial;

public:
    QuickSerial(HardwareSerial &serial) : _used_serial(serial) {}

    void println();

    //*--------------template--------------

    //! ------------- print -------------
    template <char start_bracket = '\0',
              uint32_t spaces = 0,
              char separator = ' ',
              typename T>
    void print(const T &value)
    {
        if (start_bracket != '\0')
        {
            _used_serial.print(start_bracket);
            if (spaces > 0)
                _used_serial.print(" ");
        }

        _used_serial.print(value);

        if (start_bracket != '\0')
        {
            if (spaces > 0)
                _used_serial.print(" ");
            _used_serial.print(this->get_end_bracket_from_start_bracket(start_bracket));
        }
    }

    template <char start_bracket = '\0',
              uint32_t spaces = 0,
              char separator = ' '>
    void print(const byte &value)
    {
        if (start_bracket != '\0')
        {
            _used_serial.print(start_bracket);
            if (spaces > 0)
                _used_serial.print(" ");
        }

        _used_serial.print("0x");
        if (value < 16)
            _used_serial.print("0");
        _used_serial.print(value, HEX);

        if (start_bracket != '\0')
        {
            if (spaces > 0)
                _used_serial.print(" ");
            _used_serial.print(get_end_bracket_from_start_bracket(start_bracket));
        }
    }

    template <char start_bracket = '\0',
              uint32_t spaces = 0,
              char separator = ' ',
              typename T,
              size_t N>
    void print(const T (&array)[N])
    {
        if (start_bracket != '\0')
        {
            _used_serial.print(start_bracket);
            if (spaces > 0)
                print_this_spaces(spaces);
        }

        for (size_t i = 0; i < N; ++i)
        {
            print(array[i]);

            if (i < N - 1)
            {
                if (spaces > 0)
                    print_this_spaces(spaces);
                _used_serial.print(separator);
                if (spaces > 0)
                    print_this_spaces(spaces);
            }
        }

        if (start_bracket != '\0')
        {
            if (spaces > 0)
                print_this_spaces(spaces);
            _used_serial.print(get_end_bracket_from_start_bracket(start_bracket));
        }
    }

    template <char start_bracket = '\0',
              uint32_t spaces = 0,
              char separator = ' '>
    void print(const bool &valore)
    {
        _used_serial.print(valore ? "'true'" : "'false'");
    }

    template <char start_bracket = '\0',
              uint32_t spaces = 0,
              char separator = ' ',
              size_t N>
    void print(const char (&str)[N]) // se si vuole stampare direttamente una stringa (esempio: Serial.print("ciao"); viene interpretato come un array di char)
    {
        if (start_bracket != '\0')
        {
            _used_serial.print(start_bracket);
            if (spaces > 0)
                print_this_spaces(spaces);
        }

        _used_serial.print(str);

        if (start_bracket != '\0')
        {
            if (spaces > 0)
                print_this_spaces(spaces);
            _used_serial.print(get_end_bracket_from_start_bracket(start_bracket));
        }
    }

    template <char start_bracket = '\0',
              uint32_t spaces = 0,
              char separator = ' ',
              typename T, typename... Args>
    void print(const T &first, const Args &...others)
    {
        if (start_bracket != '\0')
        {
            _used_serial.print(start_bracket);
            if (spaces > 0)
                _used_serial.print(" ");
        }

        print(first);

        print_this_spaces(spaces);

        _used_serial.print(separator);

        print_this_spaces(spaces);

        print<'\0', spaces, separator>(others...);

        if (start_bracket != '\0')
        {
            if (spaces > 0)
                _used_serial.print(" ");
            _used_serial.print(get_end_bracket_from_start_bracket(start_bracket));
        }
    }

    //! ------------- println -------------
    template <typename T>
    void println(const T &first)
    {
        print(first);
        _used_serial.println();
    }

    template <typename T, typename... Args>
    void println(const T &first, const Args &...others)
    {
        print(first, others...);
        _used_serial.println();
    }

    template <char start_bracket = '\0',
              uint32_t spaces = 0,
              char separator = ' ',
              typename... Args>
    void println(const Args &...args)
    {
        print<start_bracket, spaces, separator>(args...);
        _used_serial.println();
    }

protected:
    char get_end_bracket_from_start_bracket(const char &);

    void print_this_spaces(uint32_t spaces)
    {
        for (uint32_t i = 0; i < spaces; i++)
        {
            _used_serial.print(" ");
        }
    }
};
