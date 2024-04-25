#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

/**
 * _printf_rot - Prints a rot'ed string
 * @format: The format of the string
 * @...: The variable numbe of arguments
 * Return: The number of char printed (excluding the nul byte)
 */
int _printf_rot(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'R')
		{
			format += 2;
			count += handle_rot_string(args);
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
 * handle_rot_string - Handles the ROT13 string conversion specifier
 * @args: The variable argument list
 * Return: The number of characters printed (excluding the null byte)
 */
int handle_rot_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str != NULL)
	{
		while (*str)
		{
			if (isalpha(*str))
			{
				char base = islower(*str) ? 'a' : 'A';

				_putchar(((*str - base + 13) % 26) + base);
				count++;
			}
			else
			{
				_putchar(*str);
				count++;
			}
			str++;
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
	printf("The ROT13-encoded string of '%s' is '%R'\n", "khanyiso");
	printf("The ROT13-encoded string of '%s' is '%R'\n", "ntloko");
	printf("The ROT13-encoded string of '%s' is '%R'\n", "12345");
	printf("The ROT13-encoded string of '%s' is '%R'\n", "abc def");
	return (0);
}
