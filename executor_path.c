#include "shell.h"

/**
 * _execute_path - Execute commands gotten from path
 * @path: Path
 * @arCmd: Array of arguments
 * @ptr: Name of program
 * @env: Environment variables
 * @ptr_num: Pointer to error count
 *
 */
void _execute_path(char *path, char **arCmd, char __attribute__((unused)) *ptr,
		char **env, int *ptr_num)
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
		if (execve(path, arCmd, env) == -1)
		{
			perror(arCmd[0]);
		}
	}
	else
	{
		wait(NULL);
		(*ptr_num)++;
	}
}
