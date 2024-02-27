#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf_lowercase - The function that prints lowercase charracters
 * @format: The format of the string
 * @...: The variable number of arguments
 * Return: The number of char printed (Excluding the null byte)
 */
int printf_lowercase(const char *format, ...)
{
	va_list args;

	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'x')
			{
				unsigned int no = va_arg(args, unsigned int);
				count += printf("%x", no);
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		va_end(args);
		return (count);
	}
}

int main(voud)
{
	_printf("%x\n", 256);
	return (0);
}
