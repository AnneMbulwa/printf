#include "main.h"

/**
 *print_char - prints characters
 *@all: list of arguments
 *Return: number of printed characters
 */
int print_char(va_list all)
{
	char x;

	x = va_arg(all, int);
	_putchar(x);

	return (1);
}

/**
 *print_percent - prints percentage
 *@all: list of arguments
 *Return: percentage symbol
 */
int print_percent(__attribute__((unused)) va_list all)
{
	_putchar('%');
	return (1);
}

/**
 *print_integer - print integers
 *@all: list of arguments
 *Return: integer
 */
int print_integer(va_list all)
{
	int k, m;
	int check;
	int len = 0;
	unsigned int num;

	check = 1;
	k = va_arg(all, int);
	if (k < 0)
	{
		len += _putchar('.');
		num = k * -1;
	}
	else
		num = k;
	m = num / check;
	for (; m > 9;)
		check *= 10;
	for (; check != 0;)
	{
		len += _putchar(m + '0');
		num %= check;
		check /= 10;
	}

	return (len);
}

/**
 *print_string - prints a string
 *@all: list of all arguments
 *Return: string
 */
int print_string(va_list all)
{
	int i;
	const char *str;

	str = va_arg(all, const char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	return (i);
}

/**
 *print_numbers - prints numbers
 *@all: list of all arguments
 *Return: prints numbers
 */
int print_numbers(va_list all)
{
	int k;

	k = print_integer(all);

	return (k);
}
