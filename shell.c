#include "shell.h"

/**
 * main - Making a simple shell
 * @argc: Argument count
 * @argv: Argument Vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *cmd = NULL, **arr_cmd;
	ssize_t res;
	size_t cmdlen = 0;
	int active = 1, index;

	if (isatty(STDIN_FILENO))
	{
		while (active)
		{
			if (write(STDOUT_FILENO, "my_shell$ ", 10) == -1)
			{
				write(STDERR_FILENO, "Couldn't write\n", 15);
				exit(1);
			}
			res = getline(&cmd, &cmdlen, stdin);
			if (res == -1)
			{
				free(cmd);
				cmd = NULL;
				write(STDERR_FILENO, "\n", 1);
				exit(2);
			}
			arr_cmd = get_cmd(cmd);
			_execute(arr_cmd);
			free_arrcmd(arr_cmd);
			free(cmd);
			cmd = NULL;
		}
	}
	else
	{
		res = getline(&cmd, &cmdlen, stdin);
		if (res == -1)
		{
			perror(cmd);
			exit(4);
		}
		arr_cmd = get_cmd(cmd);
		_execute(arr_cmd);
		free_arrcmd(arr_cmd);
	}

	free(cmd);
	cmd = NULL;
	return (0);
}
