#include "main.h"
/**
 *get_width - calculteas the width
 *@format: format
 *@args: list of arguments
 *@p: parameters
 *Return: width
 */
int get_width(const char *format, va_list args, int *p)
{
	int x;
	int width = 0;

	for (x = *p + 1; format[x] != '\0'; x++)
	{
		if (is_digit(format[x]))
		{
			width *= 10;
			width += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			width = va_arg(args, int);
			break;
		}
	}
	*p = x - 1;

	return (width);
}
