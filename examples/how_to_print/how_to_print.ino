
// First, include the library and Arduino.h if necessary
#include <arduino.h>
#include <QuickSerial.h>

//--------------------------------------

// Create an object of the QuickSerial class using your preferred name (i suggest Quick_Serial).
// The parameter is a HardwareSerial object, for example Serial (commonly used for code upload and communication with the PC).
QuickSerial Quick_Serial(Serial);

//==========================================================================
//* QuickSerial Quick_Serial(Serial , 6);
//                                    ^
//   _________________________________|
//   |
//   v
// You can specify the number of digits after the decimal point in the constructor (by default it is 2).
// This behavior can be configured also with the method "set_digits_after_decimal_point"
//==========================================================================

//--------------------------------------------------------------------------

void setup()
{
    Serial.begin(115200); // Initialize serial communication. QuickSerial uses the serial port only for formatting and printing, so you must initialize it yourself.

    delay(3000);

    // A basic example
    // You can use the same methods as Serial to print.
    Quick_Serial.println("Hello World!");
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    // You can concatenate different types of data. Add as many values as you want.
    Quick_Serial.println("i can use numbers! look at me:", 1, 2, 3);
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    // You can also choose the start bracket using a template parameter.
    // If you use a standard opening bracket like [, {, (, <, the corresponding closing bracket will be added automatically.
    // Otherwise, the end bracket will be the same as the start bracket.
    Quick_Serial.print("i can use numbers! Now with brackets: ");
    Quick_Serial.println<'['>(1, 2, 3);
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    // You can also specify a separator between values, along with the number of spaces.
    // The template parameter order is: <start_bracket, spaces, separator>
    Quick_Serial.print("i can use numbers! Now with brackets and separator: ");
    Quick_Serial.println<'{', 1, '-'>(1, 2, 3);
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    // You can print any type of value, including combinations of strings and numbers.
    Quick_Serial.println("Hello Timmy, i need", 6, "cookies");
    Quick_Serial.println();

    Quick_Serial.print("this is my lottery number: ");
    Quick_Serial.println<'[', 1, ','>(25, 48, 9, 22, 61);
    Quick_Serial.println("I hope you win the lottery!");
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    // Boolean values are printed as 'true' or 'false'.
    Quick_Serial.println("this is my boolean value:", true, "And this is the other one:", false);
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    // Byte values are automatically printed in hexadecimal (0x..) format.
    byte byte_value = 0x6F;
    Quick_Serial.println("this is a byte:", byte_value);
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    //
    double double_value = 3.141592;
    Quick_Serial.set_digits_after_decimal_point(2);
    Quick_Serial.println("this is a double with 2 digits:", double_value);
    Quick_Serial.set_digits_after_decimal_point(6);
    Quick_Serial.println("this is the same double with 6 digits:", double_value);
    Quick_Serial.set_digits_after_decimal_point(2); // Restore the default value
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    // one more thing
    // if you have and array, you can print it like this

    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Quick_Serial.print("this is an array: ");
    Quick_Serial.println<'['>(numbers);
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    // or if you want a separator
    Quick_Serial.println<'{', 1, ','>(numbers);
    Quick_Serial.println<'<', 2, '-'>(numbers);
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    // You can also concatenate arrays
    int numbers2[] = {3, 7, 9};
    uint16_t numbers3[] = {5, 8, 6};
    Quick_Serial.println("concatenated arrays:");
    Quick_Serial.println(numbers2, numbers3);
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    // You can mix arrays with other values:
    Quick_Serial.println("this is an array:", numbers2, "and this is another one:", numbers3);
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    // When printing arrays with separators, this approach is recommended:
    Quick_Serial.print("This is an array: ");
    Quick_Serial.println<'[', 1, ','>(numbers2);
    Quick_Serial.print("And this is another one: ");
    Quick_Serial.println<'[', 1, ','>(numbers3);
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    //  If you want to print a byte array, it will be formatted automatically:
    byte byte_array[] = {0x01, 0x02, 0x5F, 0xB4};
    Quick_Serial.println("this is a byte array:", byte_array);
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    // You can also add brackets, separators, etc...
    Quick_Serial.println<'['>(byte_array);
    Quick_Serial.println<'[', 1, ','>(byte_array);
    Quick_Serial.println();

    //--------------------------------------------------------------------------
    // You can also print array with index
    static byte bytes[] = {2, 4, 7, 5, 33, 65, 100, 200, 22, 29, 79, 99, 15};
    Quick_Serial.print_byte_array_with_index(bytes);
    Quick_Serial.println();
}

void loop()
{
    delay(100000);
}