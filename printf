#include "main.h"

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - is the Printf function
 * @format: data format.
 * Return: chars Printed.
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				printed_chars += BUFF_SIZE;
			}
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			i++; // Move past '%'
			int flags = get_flags(format, &i);
			int width = get_width(format, &i, list);
			int precision = get_precision(format, &i, list);
			int size = get_size(format, &i);
			int printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
			if (printed == -1)
			{
				va_end(list);
				return (-1);
			}
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);
	printed_chars += buff_ind;

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - it will Print the contents ofa buffer if its there.
 * @buffer: Array of chars
 * @buff_ind: is the Index which will add the next char and represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}
