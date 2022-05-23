#include "shell.h"

/**
 * builtin_func - Choose bulitin function
 * @cmd: Command passed
 * @ptr_err: Pointer to error counter
 * @prg: Name of program
 *
 * Return: 1 - On success
 *         0 - On failure
 */
int builtin_func(char *cmd, int *ptr_err, char *prg)
{
	int ctrl;

	if (builtin_check(cmd, "exit") == 1)
	{
		ctrl = exit_shell(cmd);
		if (ctrl == -1)
			exit_err(prg, cmd, ptr_err);
		return (1);
	}
	if (builtin_check(cmd, "env") == 1)
	{
		print_env(environ, ptr_err);
		return (1);
	}
	if (builtin_check(cmd, "setenv") == 1)
	{
		ctrl = _setenv(cmd, ptr_err);
		if (ctrl == -1)
			write(STDERR_FILENO, "Unable to set environment variable\n", 35);
		return (1);
	}
	if (builtin_check(cmd, "unsetenv") == 1)
	{
		ctrl = _unsetenv(cmd, ptr_err);
		if (ctrl == -1)
			write(STDERR_FILENO, "Unable to remove environment variable\n", 38);
		return (1);
	}
	return (0);
}
