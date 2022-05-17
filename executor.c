#include "shell.h"

/**
 * _execute - Execute the commands
 * @arr_cmd: Array of command and arguments
 */
void _execute(char **arr_cmd)
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
		if (execve(arr_cmd[0], arr_cmd, NULL) == -1)
			perror("./shell");
	}
	else
	{
		wait(NULL);
	}
}
