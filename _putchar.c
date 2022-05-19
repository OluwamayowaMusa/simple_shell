#include "shell.h"

/**
 * _putchar - Write a character to file stream
 * @c: Char paased
 *
 * Return: charWritten
 */
int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, sizeof(c)));
}
