#include "main.h"
/**
 *get_size - calculates size of argument
 *@format: format
 *@p: parameters
 *Return: size
 */
int get_size(const char *format, int *p)
{
	int x = *p + 1;
	int size = 0;

	if (format[x] == 'l')
		size = SIZE_LONG;
	else if (format[x] == 'h')
		size = SIZE_SHORT;
	if (size == 0)
		*p = x - 1;
	else
		*p = x;

	return (size);
}
