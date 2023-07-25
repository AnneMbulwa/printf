#include "main.h"
/**
 *get_func - print argument based of function type
 *@args: list of arguments
 *@format: format
 *Return: 1 0r 2
 */
int get_func(const char *format, va_list args, ...)
{
	int i = 0;
	int length = 0;
	int char_print = -1;

	get_func[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', Print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print reverse}, {'R', print_rot13}, {'\0', NULL}
	};
	for (i = 0; get_func[i].format != '\0'; i++)
	{
		if (format[*index] == get_func[i].format)
			return (get_func[i].f(args, flags, size, precision, width));
	}
	if (get_func[i].format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		length += write(1, '%%', 1);
		if (format[*index - 1] = ' ')
			length += write(1, ' ', 1);
		else if (width)
		{
			--(*index);
			while (format[*index] = ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		length += write(1, &format[*index], 1);
		return (length);
	}
	return (char_print);
}
