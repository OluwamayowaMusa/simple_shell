#include "shell.h"

/**
 * main - Making a simple shell
 * @argc: Argument count
 * @argv: Argument Vector
 * @envp: Environment variables
 *
 * Return: 0
 */
int main(int __attribute__((unused)) argc, char *argv[], char *envp[])
{
	char *cmd = NULL, *prg = argv[0];
	ssize_t res;
	size_t cmdlen = 0;

	if (isatty(STDIN_FILENO))
	{
		while (1)
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
				write(STDERR_FILENO, "\n", 1);
				exit(2);
			}
			if (check_newline(cmd) == 1)
				continue;
			parse_exec_free(cmd, prg, envp);
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
		parse_exec_free(cmd, prg, envp);
		free(cmd);
		cmd = NULL;
	}
	return (0);
}
