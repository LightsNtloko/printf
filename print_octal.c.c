#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _print_octal - The funtion that prints an octal value
 * @format: The format of the string
 * @...: The vaiable number of arguments
 * 
 * Return: The number of char to be printed (exluding null byte)
 */
int print_octal(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'o')
			{
				unsigned in no = va_arg(args, unsigned int);
				count += printf("%o", no);
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

int main(void)
{
	_printf("%o\n", 246);
	return (0);
}
