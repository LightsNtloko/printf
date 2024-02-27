#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

void printf_string(va_list kay);
int printf_char(va_list kay);
int _putchar(char c);
int printf(const char *format, ...);
int strlen(char *str);
int strlend(const char *str);
int print_37(void);
int print_int(const char *format, ...);
int print_binary(const char *format, ...);
int print_unsigned(const char *format, ...);
int print_octal(const char *format, ...);
int printf_lowercase(const char *format, ...);
int printf_uppercase(const char *format, ...);
int printf_nonprint(const char *format, ...);
int print_string_containing_escapes(char *str);
int printf_pointer(const char *format, ...);
int printf_banner(const char *format, ...);
int printf_width(const char, *format, ...);
int printf_precision(const char *format, ...);
int printf_zero_flag(const char *format, ...);
int printf_behaviour(const char *format, ...);
int printf_rev(const char *format, ...);
int printf_rot(const char *format, ...);
static int print_number_with_zero_padding(int width, int no);
static void handle_zero_flag(const char **format, va_list args, int *count);


#endif
