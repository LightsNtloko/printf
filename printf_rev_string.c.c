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

	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'r')
		{
			format += 2;

			char *str = va_arg(args, char *);


			if (str != NULL)
			{
				int length = strlen(str);
				for (int i = length - 1; i >= 0; i--)
				{
					if (str[i] < 32 || str[i] >= 127)
					{
						printf("\\x%02X", (unsigned char)str[i]);
						count += 4;
					}
					else
					{
						_putchar_(str[i]);
						count++;
					}
				}
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
	_printf("The reversed string of '%s' is '%r'\n", "Khanyiso");
	_printf("The reversed string of '%s' is '%r'\n", "ntloko");
	_printf("The reversed string of '%s' is '%r'\n", "56789");
	_printf("The reversed string of '%s' is '%r'\n", "abc def");
	return (0);
}
