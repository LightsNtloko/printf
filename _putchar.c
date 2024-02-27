#include <unistd.h>

/**
 * _putchar - Communicates a character to (stdout)
 * @c: The character to be communicated
 *
 * Return: On success the character communicated as an unsigned char,
 * On error, communicate, EOF and sets errno appropriately.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}
