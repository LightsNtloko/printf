#include "main.h"

/**
 * printf_char - A function that prints a character.
 * @kay: The argument
 * Return: 1.
 */
int printf_char(va_list kay)
{
	char str;

	str = va_arg(kay, int);
	_putchar(str);
	return (1);
}
