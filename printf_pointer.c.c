#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf_pointer - A function that prints a pointer
 * @format: Thformat of the string
 * @...: The variable number of arguments
 *
 * Return: The number of char printed (excluding the null byte)
 */
int _printf_pointer(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'p')
			{
				void *ptr = va_arg(args, void *);
				count += printf("%p", ptr);
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
	int no = 123;
	_printf("Pointer address: %p\n", (void *)&no);
	return (0);
}
