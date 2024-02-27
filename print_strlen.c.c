#include "main.h"

/**
 * _strlen - Function thea returns a the length of a string
 * @str: The string pointer
 *
 * Return: 1.
 */
int _strlen(char *str)
{
	int k;

	for (k = 0; str[k] != 0; k++);

	return (k);
}
/**
 * _strlend - The strlen function for constant char
 * @str: The constant char pointer
 *
 * Return: 1.
 */
int _strlen(const char *str)
{
	int k;

	for (k = 0; str[k] != 0; k++);

	return (1);
}
