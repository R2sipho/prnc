#include "main.h"

/**
 * handle_print -is a function that Prints an argument based on its type
 * @fmt: is the Formatted string which print the arguments
 * @ind: is the Pointer that points the  current index in the format string
 * @list: is a List of arguments to be printed
 * @buffer: is the Buffer array that handle print function
 * @flags: will Calculates active flags
 * @width: will  Get width
 * @precision: Precision specification
 * @size: specific size
 * Return: a Number of characters printed, or -1 for unknown format
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
                 int flags, int width, int precision, int size)
{
    int i, unknown_len = 0;
    int printed_chars = -1;

    fmt_t fmt_types[] = {
        {'c', print_char}, {'s', print_string}, {'%', print_percent},
        {'i', print_int}, {'d', print_int}, {'b', print_binary},
        {'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
        {'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
        {'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
    };

    for (i = 0; fmt_types[i].fmt != '\0'; i++)
    {
        if (fmt[*ind] == fmt_types[i].fmt)
            return fmt_types[i].fn(list, buffer, flags, width, precision, size);
    }

    if (fmt_types[i].fmt == '\0')
    {
        if (fmt[*ind] == '\0')
            return -1;

        unknown_len += write(1, "%%", 1);

        if (fmt[*ind - 1] == ' ')
            unknown_len += write(1, " ", 1);
        else if (width)
        {
            (*ind)--;
            while (fmt[*ind] != ' ' && fmt[*ind] != '%')
                (*ind)--;
            if (fmt[*ind] == ' ')
                (*ind)--;
            return 1;
        }

        unknown_len += write(1, &fmt[*ind], 1);
        return unknown_len;
    }

    return printed_chars;
}
