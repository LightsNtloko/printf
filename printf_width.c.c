#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf_width - A function that prints the width of a string
 * @format: The format of the string
 * @...: The variable number of arguments
 *
 * Return: The number or char printed (excluding the null byte)
 */
int _printf_width(const char *format, ...)
{
	va_list args;

	int count = 0;

	va_start(args, format);
	count = process_format(format, args);
	va_end(args);

	return (count);
}

/**
 * process_format - Processes the format string for width formatting
 * @format: The format string
 * @args: The variable argument list
 * Return: The number of characters printed (excluding the null byte)
 */
int process_format(const char *format, va_list args)
{
	int count = 0;
	int width = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			width = 0;

			if (*format >= '0' && *format <= '9')
			{
				while (*format >= '0' && *format <= '9')
				{
					width = width * 10 + (*format - '0');
					format++;
				}
			}
			count += handle_format(*format, args, width);
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
 * handle_format - Handle different format specifiers
 * @specifier: The format specifier
 * @args: The variable argument list
 * @width: The width
 *
 * Return: The number of characters printed
 */
int handle_format(char specifier, va_list args, int width)
{
	int count = 0;

	switch (specifier)
	{
	case 'd':
	case 'i':
		count += printf("%*d", width, va_arg(args, int));
		break;
	case 'u':
		count += printf("%*u", width, va_arg(args, unsigned int));
		break;
	case 'o':
		count += printf("%*o", width, va_arg(args, unsigned int));
		break;
	case 'X':
		count += printf("%*x", width, va_arg(args, unsigned int));
		break;
	default:
		_putchar('%');
		_putchar(specifier);
		count += 2;
		break;
	}
	return (count);
}

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
	_printf_width("%10d\n", 123);
	_printf_width("%5u\n", 1234);
	_printf_width("%8o\n", 123);
	_printf_width("%6X\n", 255);

	return (0);
}
