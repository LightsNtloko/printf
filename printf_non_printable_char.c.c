#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * printf_nonprint - The function that prints non printable char
 * @format: The format of the string
 * @...: The variable number of arguments
 *
 * Return: The number of char printed (excluding the null byte)
 */
int printf_nonprint(const char *format, ...)
{
	va_list args;

	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'S')
			{
				char *str = va_arg(args, char *);

				count += print_string_containing_escapes(str);
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
 * print_string_containing_escapes - A function that prints a string
 * with series on non-printable char
 * @str: The string to be printed
 *
 * Return: The number of char to be printed
 */
int print_string_containing_escapes(char *str)
{
	int count = 0;

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			count += printf("\\x%02X", *str);
		}
		else
		{
			_putchar(*str);
			count++;
		}
		str++;
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
	printf_nonprint("%S\n", "Best\nSchool");
	return (0);
}
