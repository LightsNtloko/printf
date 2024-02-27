#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf_len_modifier - A function that prints length modifiers
 * @format: The format of the string
 * @...: The variable number of arguments
 *
 * Return: The number of char printed (excluding null byte)
 */
int _printf_len_modifier(const char *format, ...)
{
	va_list args;

	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;


			int long_modifier = 0;
			int short_modifier = 0;

			while (*format == 'l' || *format == 'h')
			{
				if (*format == 'l')
					long_modifier++;
				else if (*format == 'h')
					short_modifier++;
				format++;
			}

			if (*format == 'd' || *format == 'i')
			{
				if (long_modifier == 2)
				{
					long long no = va_arg(args, long long);
					count += printf("%lld", no);
				}
				else if (long_modifier == 1)
				{
					long no = va_arg(args, long);
					count += printf("%ld", no);
				}
				else if (short_modifier == 1)
				{
					short no = va_arg(args, int);
					count += printf("%hd", no);
				}
				else
				{
					int no = va_arg(args, int);
					count += printf("%d", no);
				}
			}
			else if (*format == 'u')
			{
				if (long_modifier == 2)
				{
					unsigned long long no = va_arg(args, unsigned long long);
					count += printf("%llu", no);
				}
				else if (long_modifier == 1)
				{
					unsigned long no = va_arg(args, unsigned long);
					count += printf("%lu", no);
				}
				else if (short_modifier == 1)
				{
					unsigned short no = va_arg(args, unsigned int);
					count += printf("%hu", no);
				}
				else
				{
					unsigned int no = va_arg(args, unsigned int);
					count += printf("%u", no);
				}
			}
			else if (*format == 'o' || *format == 'x' || *format == 'X')
			{
				if (long_modifier == 2)
				{
					unsigned long long no = va_arg(args, unsigned long long);
					if (*format == 'o')
						count += printf("%llo", no);
					else if (*format == 'x')
						count += printf("%llx", no);
					else if (*format == 'X')
						count += printf("%llX", no);
				}
				else if (long_modifier == 1)
				{
					unsigned long no = va_arg(args, unsigned long);
					if (*format == 'o')
						count += printf("%lo", no);
					else if (*format == 'x')
						count += printf("%lx", no);
					else if (*format == 'X')
						count += printf("%lX", no);
				}
				else if (short_modifier == 1)
				{
					unsigned short no = va_arg(args, unsigned int);
					if (*format == 'o')
						count += printf("%ho", no);
					else if (*format == 'x')
						count += printf("%hx", no);
					else if (*format == 'X')
						count += printf("%hX", no);
				}
				else
				{
					unsigned int no = va_arg(args, unsigned int);
					if (*format == 'o')
						count += printf("%o", num);
					else if (*format == 'x')
						count += printf("%x", num);
					else if (*format == 'X')
						count += printf("%X", num);
				}
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

	int main(void)
	{
		long long no1 = 123456789123456789;
		_printf("%lld\n", no1);

		unsigned long no2 = 4294967295;
		_printf("%lu\n", no2);

		short no3 = -12345;
		_printf("%hd\n", no3);

		unsigned int no4 = 255;
		_printf("%hx\n", no4);


		return (0);
	}
}
