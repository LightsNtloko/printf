#include "main.h"

/**
 * _printf - The function imitates printf
 * @format: The identifier to look for
 * 
 * Return: An integer
 */
int _printf(const char *format, ...)
{
	match m[] =
	{
		{"%b", printf_binary},
		{"%%", print_37},
		{"%c", printf_char},
		{"%d", _printf_int},
		{"%i", _printf_int},
		{"%u", _printf_unsigned},
		{"%o", _printf_octal},
		{"%x", printf_lowercase},
		{"%X", printf_uppercase},
		{"%s", _printf_str},
		{"%r", _printf_rev},
		{"%R", _printf_rot},
		{"%u", print_unsigned},
		{"%o", print_oct},
		{"%x", print_hex},
		{"%X", print_HEX},
		{"%s", printf_nonprint},
		{"%p", print_pointer},
	}

	va_list args;
	int i = 0, len = 0;
	int j;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		j = 17;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len = len + m[j].f(args);
				i = i + 2;
				goto end;
			}
			j--;
		}
		_putchar(format[i]);
		i++;
		len++;
	}
end:
	va_end(args);
	return (len);
}
