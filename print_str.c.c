#include "main.h"

/**
 * _printf_str - A function that prints a string
 * @kay: The string t be printed
 *
 * Return: The length of the string
 */
int _printf_str(va_list kay)
{
	char *str;
	int k;
	int length;

	str = va_arg(kay, char *);
	if (str == NULL)
	{
		str = "(null)";
		length = _strlen(str);
		for (k = 0; k < length; k++)
			_putchar(str[k]);
	}
	else
	{
		length = _strlen(str);
		for (k = 0; k < length; k++)
			_putchar(str[k]);
	}
	return (length);
}
