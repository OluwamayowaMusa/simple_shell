#include "shell.h"

/**
 * _strcmp - Compare string literals
 * @s1: First String
 * @s2: Second String
 *
 * Return: 0 - If the same
 *         res - Difference between the first different char
 */
int _strcmp(char **s1, char *s2)
{
	char *temp = strtok(*s1, "=");
	int index, res = 0;

	for (index = 0; temp[index] && s2[index]; index++)
	{
		res = temp[index] - s2[index];
		if (res != 0)
			return (res);
	}
	temp = strtok(NULL, "=");
	*s1 = temp;
	return (res);
}
