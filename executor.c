#include "shell.h"

/**
 * _execute - Execute the commands
 * @arr_cmd: Array of command and arguments
 * @ptr: Name of program
 * @env: Environment variables
 *
 */
void _execute(char **arr_cmd, char *ptr, char **env)
{
	pid_t id;

	id = fork();
	if (id == -1)
	{
		write(STDERR_FILENO, "Couldn't create child process\n", 30);
		exit(3);
	}
	if (id == 0)
	{
		if (execve(arr_cmd[0], arr_cmd, env) == -1)
			perror(ptr);
	}
	else
	{
		wait(NULL);
	}
}
