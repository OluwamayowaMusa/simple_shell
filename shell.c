#include "shell.h"

/**
 * main - Making a simple shell
 * @argc: Argument count
 * @argv: Argument Vector
 * @envp: Environment variables
 *
 * Return: 0
 */
int main(int __attribute__((unused)) argc, char *argv[])
{
	char *cmd = NULL, *prg = argv[0], *cmdLine;/*Without Newline*/
	ssize_t res;
	size_t cmdlen = 0;
	int ctrl, err_count = 0;

	environ = _copyenv();
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			cmd = NULL;
			cmdlen = 0;
			if (write(STDOUT_FILENO, "my_shell$ ", 10) == -1)
			{
				write(STDERR_FILENO, "Couldn't write\n", 15);
				exit(1);
			}
			res = getline(&cmd, &cmdlen, stdin);
			if (res == -1)
			{
				free(cmd);
				free_arrcmd(environ);
				write(STDERR_FILENO, "\n", 1);
				exit(2);
			}
			if (check_newline(cmd, &err_count) == 1)
				continue;
			cmdLine = rmv_newline(cmd);
			if (exit_check(cmdLine) == 1)
			{
				ctrl = exit_shell(cmdLine);
				if (ctrl == -1)
					exit_err(prg, cmdLine, &err_count);
				free(cmdLine);
				continue;
			}
			if (envCmd(cmdLine) == 1)
			{
				print_env(environ, cmdLine, &err_count);
				continue;
			}
			if (check_setenv(cmdLine) == 1)
			{
				ctrl = _setenv(cmdLine, &err_count);
				if (ctrl == 0)
					printf("Good\n");
				if (ctrl == -1)
					printf("Error\n");
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
			perror(cmd);
			exit(4);
		}
		cmdLine = rmv_newline(cmd);
		parse_exec_free(cmdLine, prg, environ, &err_count);
		free(cmdLine);
		cmdLine = NULL;
	}
	return (0);
}
