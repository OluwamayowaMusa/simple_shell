#include "shell.h"

/**
 * _atoi - Convert string to intergers
 * @s: String passed
 *
 * Return: Integer
 */
int _atoi(char *s)
{
	unsigned int num, i;
	int sign;

	sign = 1;
	num = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = (s[i] - '0') + num * 10;

			if (s[i + 1] == ' ')
				break;
		}
		else if (s[i] == '-')
		{
			sign *= -1;
		}
	}
	return (num * sign);
}

/**
 * _isdigit - check if a character is a digit
 * @c: Character pass
 *
 * Return: 1 - if digit
 *         0 - otherwise
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
