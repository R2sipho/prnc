#include "main.h"

/**
 * get_width - it Calculates the width for a printing
 * @format: is the Formatted string that print the arguments
 * @i: is the Pointer that points current index in the format string
 * @list: a List of arguments to be printed
 *
 * Return: Width.
 */
int get_width(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int width = 0;

    while (format[curr_i] != '\0')
    {
        if (is_digit(format[curr_i]))
        {
            width *= 10;
            width += format[curr_i] - '0';
            curr_i++;
        }
        else if (format[curr_i] == '*')
        {
            width = va_arg(list, int);
            curr_i++;
            break;
        }
        else
        {
            break;
        }
    }

    *i = curr_i - 1;

    return width;

