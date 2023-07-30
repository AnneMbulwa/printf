#include "main.h"
/**
 *get_func - calculates based on function selected
 *@format: format
 *@all: list of all arguments
 *@get_func_list: array of all function
 *Return: charactes printed
 */
int get_func(const char *format, fmt_t get_func_list[], va_list all)
{
	int a, b;
	int chars_print = 0, call;

	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] == '%')
		{
			for (b = 0; get_func_list[b].fmt != NULL; b++)
				if (format[a + 1] == get_func_list[b].fmt[0])
				{
					call = get_func_list[b].fn(all);
					if (call == -1)
						return (-1);
					chars_print += call;
					break;
				}
			if (get_func_list[b].fmt == NULL && format[a + 1] != ' ')
			{
				if (format[a + 1] != '\0')
				{
					_putchar(format[a]);
					_putchar(format[a + 1]);
					chars_print += 2;
				}
				else
					return (-1);
			}
			a += 1;
		}
		else
		{
			_putchar(format[a]);
			chars_print++;
		}
	}
	return (chars_print);
}
