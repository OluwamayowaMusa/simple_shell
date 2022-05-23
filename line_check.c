#include "shell.h"

/**
 * check_newline - check for new line
 * @cmd: Command entered
 * @ptr: Pointer to error counter
 *
 * Return: 1 - if newline found
 *         0 - otherwise
 */
int check_newline(char *cmd, int *ptr)
{
	char *s, *temp;

	s = _strdup(cmd);
	temp = strtok(s, " ");
	if (temp[0] == 10)
	{
		free(s);
		free(cmd);
		(*ptr)++;
		return (1);
	}
	free(s);
	return (0);
}


/**
 * rmv_newline - Remove newline
 * @s: String passed
 *
 * Return: String without newline
 */
char *rmv_newline(char *s)
{
	char *str;
	int len, index;

	len = _strlen(s);
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	for (index = 0; index < len; index++)
	{
		if (index != len - 1)
			str[index] = s[index];
		else
			str[index] = '\0';
	}
	free(s);
	s = NULL;
	return (str);
}


/**
 * builtin_check - Check for built-in function
 * @cmd: Command passed
 * @str: Bulitin function
 *
 * Return: 1 - If built in is passed
 *         0 - otherwise
 */
int builtin_check(char *cmd, char *str)
{
	char *s, *temp;
	int index, len, len1, res;

	s = _strdup(cmd);
	temp = strtok(s, " ");
	len = _strlen(temp);
	len1 = _strlen(str);
	if (len1 != len)
	{
		free(s);
		return (0);
	}
	for (index = 0; index < len && str[index]; index++)
	{
		res = temp[index] - str[index];
		if (res != 0)
		{
			free(s);
			return (0);
		}
	}
	free(s);
	s = NULL;
	return (1);
}
