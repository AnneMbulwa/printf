#include "main.h"
/**
 *get_precision - calculates the precision
 *@format: format
 *@p: parameters
 *@args: list of arguments
 *Return: precision
 */
int get_precision(const char *format, int *p, va_list args)
{
	int x = *p + 1;
	int precision = -1;

	if (format[x] != '.')
		return (precision);
	precision = 0;
	for (x += 1; format[x] != '\0'; x++)
	{
		if (is_digit(format[x]))
		{
			precision *= 10;
			precision += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*p = x - 1;

	return (precision);
}
