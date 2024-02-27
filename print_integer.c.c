#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * print_int - Function that prints an integer
 * @format: The format of the string
 * @...: The number of of arguments
 * Return: The number of char printed (excluding null byte)
 */
int _print_int(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int no = va_arg(args, int);
				char buffer[24];
				int kay = sprintf(buffer, "%d", no);
				write(1, buffer, kay);
				count += kay;
			}
			else if (*format == '%')
			{
				write(1, "%", 1)
					count++;
			}
		}
		else
		{
			write(1, format, 1)
				count++;
		}

		var_end(args);
		return (count);
	}
}
