#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int p, printed = 0, char_print = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (p = 0; format && format[p] != '\0'; p++)
	{
		if (format[p] != '%')
		{
			buffer[buff_index++] = format[p];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			char_print++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &p);
			width = get_width(format, &p, args);
			precision = get_precision(format, &p, args);
			size = get_size(format, &p);
			++p;
			printed = get_func(format, &p, args, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			char_print += printed;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(args);

	return (char_print);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_index: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
