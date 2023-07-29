#include "main.h"

/**
 * get_precision - it Calculates the precision for printing format
 * @format: is the Formatted string that print the arguments
 * @i: is a Pointer that points current index in the format string
 * @list: is a List of arguments to be printed.
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] != '.')
        return precision;

    precision = 0;
    curr_i++;

    if (format[curr_i] == '*')
    {
        curr_i++;
        precision = va_arg(list, int);
    }
    else
    {
        while (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
            curr_i++;
        }
    }

    *i = curr_i - 1;

    return precision;
}
