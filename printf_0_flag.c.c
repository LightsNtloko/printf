#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_number_with_zero_padding - Prints a number that
 * has zero padding.
 * @width: The width of the field
 * @no: The number to print
 * Return: The number of characters printed
 */
int print_number_with_zero_padding(int width, int no)
{
	return (printf("%0*d", width, no));
}

/**
 * handle_zero_flag - Handle the zero flag case
 * @format: The format of the string
 * @args: The variable number og arguments
 * @count: The pointer of characters to be printed
 */
void handle_zero_flag(const char **format, va_list args, int *count)
{
	int width = 0;

	if (**format >= '1' && **format <= '9')
	{
		while (**format >= '0' && **format <= '9')
		{
			width = width * 10 + (**format - '0');
			(*format)++;
		}
	}
	if (**format == 'd' || **format == 'i')
	{
		int no = va_arg(args, int);

		*count += print_number_with_zero_padding(width, no);
	}
}

/**
 * printf_zero_flag - Function that handles zero flag characters
 * @format: The format of the string
 * @...: The variable number of arguments
 * Return: The number of characters printed (excluding bull byte)
 */
int printf_zero_flag(const char *format, ...)
{
	va_list args;
	int count = 0;
	int zero_flag = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '0')
			{
				zero_flag = 1;
				format++;
			}

			if (zero_flag)
			{
				handle_zero_flag(&format, args, &count);
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

/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	printf_zero_flag("%05d\n", 123);
	printf_zero_flag("%d\n", 123);
	return (0);
}
