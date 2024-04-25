#include "main.h"

/**
 * _printf_strlen - Function thea returns a the length of a string
 * @str: The string pointer
 *
 * Return: The length of the string
 */
int _printf_strlen(char *str)
{
	int k;

	for (k = 0; str[k] != 0; k++) {}

	return (k);
}

/**
 * _strlen - The strlen function for constant char
 * @str: The constant char pointer
 *
 * Return: The length of the string
 */
int _strlen(const char *str)
{
	int k;

	for (k = 0; str[k] != 0; k++) {}

	return (k);
}
