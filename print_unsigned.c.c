#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf_unsigned - Th function that prints an unsigned integer
 * @format: The format of te string
 * @...: The variable number or args
 *
 * Return: The number of char printed (excluding the null byte)
 */
int _printf_unsigned(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);


	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'u')
			{
				unsigned int no = va_arg(args, unsigned int);

				count += printf("%u", no);
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
