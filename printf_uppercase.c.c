#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf_uppercase - The function thaat prints uppercase characters
 * @*format: The format of the string
 * @...: The variable number of arguments
 *
 * Reurn: The number of char printed (excluding the null byte)
 */
int _printf_uppercase(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'X')
			{
				unsigned int no = va_arg(args, unsigned int);
				count += printf("%X", no);
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

int main(void)
{
	_printf("%X\n", 255);
	return (0);
}
