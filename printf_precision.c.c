#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * printf_precision - A function that controls the number of
 * decimal places for floating point numbers.
 * @format: The format of the string
 * @...: The variable number of arguments
 * Return: The number of char printed (excluding null byte)
 */
int _printf_precision(const char *format, ...)
{
	va_list args;

	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			int precision = -1;


			if (*format == '.')
			{
				format++;
				precision = 0;

				while (*format >= '0' && *format <= '9')
				{
					precision = precision * 10 + (*format - '0');
					format++
				}
			}


			if (*format == 'f')
			{
				double no = va_arg(args, double);
				if (precision >= 0)
					count += printf("%.*f", precision, no);
				else
					count += printf("%f", no);
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

int main(void)
{
	_printf("%.3f\n", 3.14159);
	_printf("%.5f\n", 123.456789);
	_printf("%f\n", 987.654321);
	return (0);
}
