#include "shell.h"

/**
 * check_newline - check for new line
 * @cmd: Command entered
 *
 * Return: 1 - if newline found
 *         0 - otherwise
 */
int check_newline(char *cmd)
{
	char *s, *temp;

	s = _strdup(cmd);
	temp = strtok(s, " ");
	if (temp[0] == 10)
	{
		free(s);
		return (1);
	}
	free(s);
	return (0);
}
