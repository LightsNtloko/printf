#include "main.h"

/**
 * _puts - A function that prints a string
 * @kay: The string t be printed
 *
 * Return: void
 */
void printf_string(va_list kay)
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
		return (length);
	}
	else
	{
		length = _strlen(str);
		for (k = 0; k < length; k++)
			_putchar(str[k]);
		return (length);
	}
}
