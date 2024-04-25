#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf_behaviour - Adjust the printing behavior to left-align the output
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
	count = process_format(format, args);
	va_end(args);

	return (count);
}

/**
 * process_format - Process the format string
 * @format: The format of the string
 * @args: The variable argument list
 * Return: The number of characters printed (excluding the null byte)
 */
int process_format(const char *format, va_list args)
{
	int count = 0;

	while (*format)
	{
		int left_align = 0;
		int width = 0;

		if (*format == '%')
		{
			format++;

			if (*format == '-')
			{
				left_align = 1;
				format++;
			}
			if (*format >= '1' && *format <= '9')
			{
				width = get_width(&format);
			}
			if (*format == 'd' || *format == 'i')
			{
				count += handle_integer(left_align, width, args);
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	return (count);
}

/**
 * get_width - Extracts the width from the format string
 * @format: The format string
 * Return: The width
 */
int get_width(const char **format)
{
	int width = 0;

	while (**format >= '0' && **format <= '9')
	{
		width = width * 10 + (**format - '0');
		(*format)++;
	}
	return (width);
}

/**
 * handle_integer - Handles integer formatting
 * @left_align: Flag indicating left alignment
 * @width: The width of the field
 * @args: The variable argument list
 * Return: The number of characters printed
 */
int handle_integer(int left_align, int width, va_list args)
{
	int count = 0;
	int no = va_arg(args, int);

	if (left_align)
		count += printf("%-*d", width, no);
	else
		count += printf("%*d", width, no);

	return (count);
}

/**
 * main - Chec the code
 *
 * Return: Always 0.
 */
int main(void)
{
	printf("%5d\n", 123);
	printf("%-5d\n", 123);
	return (0);
}
