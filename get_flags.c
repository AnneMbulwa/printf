#include "main.h"
/**
 *get_flags - calculate active flags
 *@format: format
 *@p: takes parameter
 *Return: flags
 */
int get_flags(const char *format, int *p)
{
	int j, x;
	int flags;
	const char FLAGS_CH[] = {'-', '+', '#', ' ', '0',  '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_HASH, F_SPACE, F_ZERO, 0};

	for (x = *p + 1; format[x] != '\0'; x++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[x] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
			if (FLAGS_CH[j] == 0)
				break;
	}
	*p = x - 1;

	return (flags);
}
