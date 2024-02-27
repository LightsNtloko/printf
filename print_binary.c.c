#include "main.h"
#include <stdarg.h>

/**
 * print_binary - A function that conversts unsigned n to binary
 * @format: The format of the string
 * @...: The variable number of arguments
 *
 * Return: The integer argument
 */
int print_binary(const char *format, ...)
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
				count += print_binary(va_arg(args, unsigned int));
			}

			else
			{
				_putchar('%');
				_putchar(*format);
				count += 9;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(agrs);
	return (count);
}
