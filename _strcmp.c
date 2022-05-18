#include "shell.h"

/**
 * _strcmp - Compare string literals with condtion of a character
 * @s1: First String
 * @s2: Second String
 *
 * Return: 0 - If the same
 *         res - Difference between the first different char
 */
int _strcmp(char *s1, char *s2)
{
	int index, res = 0, len = 0;

	while (*(s1 + len) != '=')
		len++;

	for (index = 0; index < len && s2[index]; index++)
	{
		res = s1[index] - s2[index];
		if (res != 0)
			return (res);
	}
	return (res);
}

/**
 * _strcmp1 - Compare string literals
 * @s1: First string
 * @s2: Second Strin
 *
 * Return: 0 - If the same
 *        res - Difference between the first different char
 */
int _strcmp1(char *s1, char *s2)
{
	int index, res = 0;

	for (index = 0; s1[index] && s2[index]; index++)
	{
		res = s1[index] - s2[index];
		if (res != 0)
			return (res);
	}

	return (res);
}
