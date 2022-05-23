#include "shell.h"

/**
 * main - Making a simple shell
 * @argc: Argument count
 * @argv: Argument Vector
 *
 * Return: 0
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	char *cmd = NULL, *prg = argv[0], *cmdLine;/*Without Newline*/
	ssize_t res;
	size_t cmdlen = 0;
	int err_count = 0;

	environ = _copyenv();
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			cmd = NULL, cmdlen = 0;
			if (write(STDOUT_FILENO, "my_shell$ ", 10) == -1)
			{
				all_err(cmd, 1);
			}
			res = getline(&cmd, &cmdlen, stdin);
			if (res == -1)
			{
				all_err(cmd, 2);
			}
			if (check_newline(cmd, &err_count) == 1)
				continue;
			cmdLine = rmv_newline(cmd);
			if (builtin_func(cmdLine, &err_count, prg) == 1)
			{
				free(cmdLine);
				continue;
			}
			parse_exec_free(cmdLine, prg, environ, &err_count);
			free(cmdLine);
			cmdLine = NULL;
		}
	}
	else
	{
		res = getline(&cmd, &cmdlen, stdin);
		if (res == -1)
		{
			all_err(cmd, 4);
		}
		if (check_newline(cmd, &err_count) == 1)
			return (0);
		cmdLine = rmv_newline(cmd);
		if (builtin_func(cmdLine, &err_count, prg) == 1)
		{
			free(cmdLine);
			return (0);
		}
		parse_exec_free(cmdLine, prg, environ, &err_count);
		free(cmdLine);
		cmdLine = NULL;
	}
	return (0);
}
