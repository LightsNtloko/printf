#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_number - Function that prints a number according to specific flags
 * @no: The number to print
 * @add_flag: The flag for printing a plus sign '+'.
 * @space_flag: The flag for printing a space sign ' '.
 * @hash_flag: The flag for printing hash sign '#'.
 * Return: The number of characters printed.
 */
static int print_number(int no, int add_flag, int space_flag, int hash_flag)
{
	int count = 0;

	if (add_flag && no >= 0)
		count += _putchar('+');
	else if (space_flag && no >= 0)
		count += _putchar(' ');

	count += printf("0x%x", no);
	return (count);
}

/**
 * process_flags - Process and handle banner flags
 * @format: The format of the string
 * @add_flag: The pointer to the flag for printing a plus sign
 * @space_flag: The pointer to the flag for printing a space sign
 * @hash_flag: The pointer to the flag for printing hash sign
 * Return: The updated format string after processing flags
 */
static const char *process_flags(const char *format, int *add_flag,
		int *space_flag, int *hash_flag)
{
	while (*format == '+' || *format == ' ' || *format == '#')
	{
		if (*format == '+')
			*add_flag = 1;
		else if (*format == ' ')
			*space_flag = 1;
		else if (*format == '#')
			*hash_flag = 1;
		format++;
	}
	return (format);
}

/**
 * printf_banner - The function that prints banners
 * @format: The format of the string
 * @...: The variable number of arguments
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int printf_banner(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;

			int add_flag = 0, int space_flag = 0, int hash_flag = 0;

			format = process_flags(format, &add_flag, &space_flag, &hash_flag);
			if (*format == 'd' || *format == 'i')
			{
				int no = va_arg(args, int);

				count += print_number(no, add_flag, space_flag, hash_flag);
			}
			else if (*format == 'x' || *format == 'X')
			{
				unsigned int no = va_arg(args, unsigned int);

				if (hash_flag && no != 0)
					count += printf("0x%x", no);
				else
					count += printf("%x", no);
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
	_printf_flag("%+d\n", 123);
	_printf_flag("% d\n", 123);
	_printf_flag("%#x\n", 255);
	return (0);
}
