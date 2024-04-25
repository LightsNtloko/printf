#include "main.h"
#include <stdarg.h>

/**
 * printf_binary - A function that conversts unsigned n to binary
 * @format: The format of the string
 * @...: The variable number of arguments
 *
 * Return: The integer argument
 */
int printf_binary(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'b')
			{
				unsigned int num = va_arg(args, unsigned int);
				unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
				
				while (mask)
				{
					_putchar((num & mask) ? '1' : '0');
					count++;
					mask >>= 1;
				}
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
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
