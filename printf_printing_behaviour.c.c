#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _print_behaviour - Adjust the printing behavior to left-align the output
 * instead of right-aligning it
 * @format: The format of the string
 * @...: The variable number of characters
 * Return: The number of char printed (excluding null byte)
 */
int _printf_behaviour(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			int left_align = 0;
			int width = 0;

			if (*format == '-')
			{
				left_align = 1;
				format++;
			}

			if (*format >= '1' && *format <= '9')
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
				if (left_align)
					count += printf("%-*d", width, no);
				else
					count += printf("%*d", width, no);
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
	_printf("%5d\n", 123);
	_printf("%-5d\n", 123);
	return (0);
}
