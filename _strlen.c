#include "shell.h"

/**
 * _strlen - length of string
 * @s: String passed
 *
 * Return: Length
 */
int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;

	return (len);
}
