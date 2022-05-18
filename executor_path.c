#include "shell.h"

/**
 * _execute_path - Execute commands gotten from path
 * @path: Path
 * @ar_cmd: Array of arguments
 * @ptr: Name of program
 * @env: Environment variables
 */
void _execute_path(char *path, char **ar_cmd, char *ptr, char **env)
{
	pid_t id;

	id = fork();
	if (id == -1)
	{
		write(STDERR_FILENO, "Couldn't create child process\n", 30);
		exit(6);
	}
	if (id == 0)
	{
		if (execve(path, ar_cmd, env) == -1)
			perror(ptr);
	}
	else
	{
		wait(NULL);
	}
}
