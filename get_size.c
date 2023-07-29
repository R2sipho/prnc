#include "main.h"

/**
 * get_size - it will Calculates the size of the argument
 * @format: is Formatted string in which to print the arguments
 * @i: is the Pointer that point current index in the format string
 *
 * Return: Size specifier.
 */
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    if (format[curr_i] == 'l')
    {
        size = S_LONG;
        if (format[curr_i + 1] == 'l')
        {
            size = S_LONGLONG;
            curr_i++;
        }
    }
    else if (format[curr_i] == 'h')
    {
        size = S_SHORT;
        if (format[curr_i + 1] == 'h')
        {
            size = S_CHAR;
            curr_i++;
        }
    }

    *i = curr_i;

    return size;
}
