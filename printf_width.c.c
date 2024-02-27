#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _print_width - A function that prints the width of a string
 * @format: The format of the string
 * @...: The variable number of arguments
 *
 * Return: The number or char printed (excluding the null byte)
 */
int _printf_width(const char, *format, ...)
{
	va_list args;
	count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			int width = 0;

			if (*format >= '0' && *format <= '9')
			{
				while (*format >= '0' && *format <= '9')
				{
					width = width * 10 + (*format - '0');
					format++;
				}
			}

			if (*format == 'd' || *format == 'i')
			{
				int no = va_arg(args, int);
				count += printf("%*d", width, no);
			}
			else if (*format == 'u')
			{
				unsigned int no = va_arg(args, unsigned int);
				count += printf("%*u", width, no);
			}
			else if (*format == 'o')
			{
				unsigned int no = va_arg(args, unsigned int);
				count += printf("%*o", width, no);
			}
			else if (*format == 'x' || *format == 'X')
			{
				unsigned int no = va_arg(args, unsigned int);
				count += printf("%*x", width, num);
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
	_printf("%10d\n", 123);
	_printf("%5u\n", 1234);
	_printf("%8o\n", 123);
	_printf("%6X\n", 255);
	
	return (0);
}
