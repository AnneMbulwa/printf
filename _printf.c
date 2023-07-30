#include "main.h"
/**
 *_printf - printf function
 *@format: format
 *Return: char printed
 */
int _printf(const char *format, ...)
{
	int chars_print;

	fmt_t get_func_list[] = {
		{"c", print_char},
		{"%", print_percent},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
	};

	va_list all;

	if (format == NULL)
		return (-1);
	va_start(all, format);
	chars_print = get_func(format, get_func_list, all);

	return (chars_print);
}
