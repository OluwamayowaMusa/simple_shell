#include "shell.h"

/**
 * _execute - Execute the commands
 * @arr_cmd: Array of command and arguments
 * @ptr: Name of program
 * @env: Environment variables
 * @ptr_num: Pointer to error count
 *
 */
void _execute(char **arr_cmd, char __attribute__((unused)) *ptr,
		char **env, int *ptr_num)
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
		{
			perror(arr_cmd[0]);
		}
	}
	else
	{
		wait(NULL);
		(*ptr_num)++;
	}
}
