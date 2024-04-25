#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf_rev - Prints string in revers for custom conversion specifiers
 * @format: The format of the string
 * @...: The variable number of arguments
 * Return: The number of char printed (excluding the null byte)
 */
int _printf_rev(const char *format, ...)
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
		if (*format == '%' && *(format + 1) == 'r')
		{
			format += 2;
			count += handle_reverse_string(args);
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
 * handle_reverse_string - Handles the reverse string conversion specifier
 * @args: The variable argument list
 * Return: The number of characters printed (excluding the null byte)
 */
int handle_reverse_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str != NULL)
	{
		int length = strlen(str);
		int i;

		for (i = length - 1; i >= 0; i--)
		{
			if (str[i] < 32 || str[i] >= 127)
			{
				printf("\\x%02X", (unsigned char)str[i]);
				count += 4;
			}
			else
			{
				_putchar(str[i]);
				count++;
			}
		}
	}

	return (count);
}

/**
 * main - Check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	printf("The reversed string of '%s' is '%r'\n", "Khanyiso");
	printf("The reversed string of '%s' is '%r'\n", "ntloko");
	printf("The reversed string of '%s' is '%r'\n", "56789");
	printf("The reversed string of '%s' is '%r'\n", "abc def");
	return (0);
}
