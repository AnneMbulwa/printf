#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

struct fmt {
	char *fmt;
	int (*fn) (va_list);
};

typedef struct fmt fmt_t;

int _putchar(char c);
int _printf(const char *format, ...);
int get_func(const char *format, fmt_t get_func_list[], va_list all);

int print_char(va_list all);
int print_percent(__attribute__((unused)) va_list);
int print_string(va_list all);
int print_numbers(va_list all);
int print_integer(va_list all);
#endif
