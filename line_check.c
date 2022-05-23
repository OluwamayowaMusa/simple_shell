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
 * exit_check - Check for exit
 * @cmd: Command entered
 *
 * Return: 1 - if exit found
 *         0 - otherwise
 */
int exit_check(char *cmd)
{
	char *s, *temp, *str = "exit";
	int len, index, res, len1;

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
	return (1);
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
 * envCmd - Check if the command env is entered
 * @cmd: Command passed
 *
 * Return: 1 - If true
 *         0 - otherwise
 */
int envCmd(char *cmd)
{
	char *str, *temp, *s = "env";
	int res, index, len, len1;

	str = _strdup(cmd);
	temp = strtok(str, " ");
	len = _strlen(temp);
	len1 = _strlen(s);
	if (len1 != len)
	{
		free(str);
		return (0);
	}
	for (index = 0; index < len && s[index]; index++)
	{
		res = temp[index] - s[index];
		if (res != 0)
		{
			free(str);
			return (0);
		}
	}
	free(str);
	str = NULL;
	return (1);
}


/**
 * check_setenv - Check setenv command
 * @cmd: Command passed
 *
 * Return: 1 - If setenv is paased
 *         0 - Otherwise
 */
int check_setenv(char *cmd)
{
	char *str, *temp, *s = "setenv";
	int index, len, len1, res;

	str = _strdup(cmd);
	temp = strtok(str, " ");
	len = _strlen(temp);
	len1 = _strlen(s);
	if (len1 != len)
	{
		free(str);
		return (0);
	}
	for (index = 0; index < len && s[index]; index++)
	{
		res = temp[index] - s[index];
		if (res != 0)
		{
			free(str);
			return (0);
		}
	}
	free(str);
	str = NULL;
	return (1);
}
