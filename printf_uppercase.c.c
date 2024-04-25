#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * printf_uppercase - The function that prints uppercase characters
 * @format: The format of the string
 * @...: The variable number of arguments
 *
 * Return: The number of char printed (excluding the null byte)
 */
int printf_uppercase(const char *format, ...)
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

/**
 * main - Check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	printf_uppercase("%X\n", 255);
	return (0);
}
