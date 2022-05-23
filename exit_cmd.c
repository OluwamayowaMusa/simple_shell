#include "shell.h"

/**
 * exit_shell - Implementing the exit function
 * @cmd: Command passed
 *
 * Return: -1 - if aragument passed is not numerical
 *
 */
int exit_shell(char *cmd)
{
	char *s, *temp;
	int num;
	int index, control;

	s = _strdup(cmd);
	temp = strtok(s, " ");
	temp = strtok(NULL, " ");
	if (temp == NULL)
	{
		free(cmd);
		free(s);
		free_arrcmd(environ);
		exit(0);
	}
	else
	{
		for (index = 0; temp[index]; index++)
		{
			control = _isdigit(temp[index]);
			if (control == 0)
			{
				free(s);
				return (-1);
			}
		}
		num = _atoi(temp);
		free(cmd);
		free(s);
		free_arrcmd(environ);
		exit(num);
	}
	return (0);
}
