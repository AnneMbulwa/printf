#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unstd.h>

#define BUFF_SIZE 1024

/*FLAGS*/
#define F_MINUS 1
#define F_PLUS 2
#define F_SPACE 16
#define F_HASH 8
#define F_ZERO 4

/*SIZES*/
#define S_SHORT 2
#define S_LONG 1

/**
 *struct fmt - Struct Op
 *@fmt: format
 *@f: function
 */
struct fmt
{
	char fmt;
	int (*f)(va_list, char[], int, int, int int)
}

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int get_func(const char *format, int *p, va_list args,
		int flags, int width, int size, int precision);

/*FUNCTIONS*/
int print_char(va_list args, char buffer[], int size,
		int width, int precision, int flags);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args, char buffer[]);
int print_binary(va_list args);
int print_unsigned(va_list args, char buffer[], int size,
		int flags, int precision, int width);
int print_octal(va_list args, char buffer[], int size,
		int width, int precision, int flags);
int print_hexa_decimal(va_list args, char buffer[], int size,
		int width, int flags, int precision);
int print_hexa_upper(va_list args, char buffer[], int size,
		int flags, int width, int precision);
int print_pointer(va_list args, char buffer[], int size,
		int flags, int width, int precision);
int print_non_printable(va_list args, char buffer[], int size,
		int flags, int width, int precision);
int print_reverse(va_list args);
int print_rot13(va_list args);

int get_flags(const char *format, int *p);
int get_precision(const char *format, int *p, va_list args);
int get_width(const char *format, int *p, va_list args);
int get_size(const char *format, int *p);

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);



int is_printable(char c);
int is_digit(char c);
int append_hexa_code(char, char[], int);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif