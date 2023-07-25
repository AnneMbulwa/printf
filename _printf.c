#include "main.h"
/**
 *_printf - print format
 *@format: format
 *Return: printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int char_print = 0, x;
	char *str;

	if (*format == NULL)
		return (-1);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
			format++;
		switch (*format)
		{
			case 'c':
				x = va_arg(args, int);
				write(1, &x, 1);
				char_print++;
				break;
			case 's':
				str = va_arg(args, char *);
				while ([str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				char_print++;
				break;
			case '%':
				write(1, '%%', 1);
				char_printed++;
				break;
			default:
				write(1, format, 1);
				char_print++;
				break;
		}
		format++;
	}
	va_end(args);

	return (char_print);
}
