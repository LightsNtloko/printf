#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * handle_oct_hex_default - Handle octal/hex without any modifiers
 * @format: The format of the string
 * @args: The variable number of arguments
 * Return: The number of characters printed (excluding null byte)
 */
int handle_oct_hex_default(const char *format, va_list args)
{
	unsigned int no = va_arg(args, unsigned int);
	int count = 0;

	if (*format == 'o')
		count += printf("%o", no);
	else if (*format == 'x')
		count += printf("%x", no);
	else if (*format == 'X')
		count += printf("%X", no);

	return (count);
}

/**
 * handle_length_modifiers - Handle length modifiers in printf
 * @format: The format of the string
 * @long_modifier: Count of 'l' modifiers
 * @short_modifier: Count of 'h' modifiers
 * @args: The variable number of arguments
 * Return: The number of characters printed (excluding null byte)
 */
int handle_len_modifiers(const char *format, int long_modifier,
		int short_modifier, va_list args)
{
	int count = 0;
	long no;
	unsigned long unsigned_no;

	if (*format == 'd' || *format == 'i')
	{
		if (long_modifier == 2 || long_modifier == 1)
		{
			no = va_arg(args, long);
			count += printf("%ld", no);
		}
		else if (short_modifier == 1)
		{
			no = va_arg(args, int);
			count += printf("%hd", no);
		}
		else
		{
			no = va_arg(args, int);
			count += printf("%d", no);
		}
	}
	else if (*format == 'u')
	{
		if (long_modifier == 2 || long_modifier == 1)
		{
			unsigned_no = va_arg(args, unsigned long);
			count += printf("%lu", unsigned_no);
		}
		else if (short_modifier == 1)
		{
			unsigned_no = va_arg(args, unsigned int);
			count += printf("%hu", unsigned_no);
		}
		else
		{
			unsigned_no = va_arg(args, unsigned int);
			count += printf("%u", unsigned_no);
		}
	}
	else
	{
		putchar(*format);
		count++;
	}
	return (count);
}
/**
 * handle_oct_hex_long_long - Handle octal/hex with 'll' modifier
 * @format: The format of the string
 * @args: The variable number of arguments
 * Return: The number of characters printed (excluding null byte)
 */
int handle_oct_hex_long_long(const char *format, va_list args)
{
	unsigned long no = va_arg(args, unsigned long);
	int count = 0;

	if (*format == 'o')
		count += printf("%lo", no);
	else if (*format == 'x')
		count += printf("%lx", no);
	else if (*format == 'X')
		count += printf("%lX", no);

	return (count);
}

/**
 * _printf_len_modifier - A function that prints length modifiers
 * @format: The format of the string
 * @...: The variable number of arguments
 * Return: The number of char printed (excluding null byte)
 */
int _printf_len_modifier(const char *format, ...)
{
	va_list args;
	int count = 0;
	int long_modifier = 0;
	int short_modifier = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			while (*format == 'l' || *format == 'h')
			{
				if (*format == 'l')
					long_modifier++;
				else if (*format == 'h')
					short_modifier++;
				format++;
			}
			count += handle_len_modifiers(format, long_modifier, short_modifier, args);
			continue;
		}
		putchar(*format);
		count++;
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
	long no1 = 123456789123456789;
	unsigned long no2 = 4294967295;
	short no3 = -12345;
	unsigned int no4 = 255;

	printf("%ld\n", no1);
	printf("%lu\n", no2);
	printf("%hd\n", no3);
	printf("%hx\n", no4);

	return (0);
}
