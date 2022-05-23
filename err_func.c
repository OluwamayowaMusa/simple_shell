#include "shell.h"

/**
 * cmd_error - Command not found
 * @name: Name of program
 * @cmd: Command passed
 * @ptr_err: Pointer to error counter
 */
void cmd_error(char *name, char *cmd, int *ptr_err)
{
	ssize_t charWritten;

	(*ptr_err)++;
	charWritten = write(STDERR_FILENO, name, _strlen(name) + 1);
	if (charWritten == -1)
		return;
	charWritten = write(STDERR_FILENO, ": ", 2);
	if (charWritten == -1)
		return;
	print_number(*ptr_err);
	charWritten = write(STDERR_FILENO, ": ", 2);
	if (charWritten == -1)
		return;
	charWritten = write(STDERR_FILENO, cmd, _strlen(cmd));
	if (charWritten == -1)
		return;
	charWritten = write(STDERR_FILENO, ": not found\n", 12);
	if (charWritten == -1)
		return;
}

/**
 * exit_err - Exit error
 * @name: Name of program
 * @cmd: Command passed
 * @ptr_err: Pointer to error counter
 */
void exit_err(char *name, char *cmd, int *ptr_err)
{
	ssize_t charWritten;

	(*ptr_err)++;
	charWritten = write(STDERR_FILENO, name, _strlen(name));
	if (charWritten == -1)
		return;
	charWritten = write(STDERR_FILENO, ": ", 2);
	if (charWritten == -1)
		return;
	print_number(*ptr_err);
	charWritten = write(STDERR_FILENO, ": ", 2);
	if (charWritten == -1)
		return;
	charWritten = write(STDERR_FILENO, cmd, sizeof(char) * 4);
	if (charWritten == -1)
		return;
	charWritten = write(STDERR_FILENO, ": Illegal number: ", 18);
	if (charWritten == -1)
		return;
	charWritten = write(STDERR_FILENO, (cmd + 5), _strlen(cmd + 5));
	if (charWritten == -1)
		return;
	_putchar('\n');
}

/**
 * access_err - Access file error
 * @ptr: Name of program
 * @cmd: Command passed
 *
 */
void access_err(char *ptr, char *cmd)
{
	ssize_t charWritten;

	charWritten = write(STDERR_FILENO, ptr, _strlen(ptr));
	if (charWritten == -1)
		return;
	charWritten = write(STDERR_FILENO, ": ", 2);
	if (charWritten == -1)
		return;
	charWritten = write(STDERR_FILENO, cmd, _strlen(cmd));
	if (charWritten == -1)
		return;
	charWritten = write(STDERR_FILENO, ": Permission denied\n", 20);
	if (charWritten == -1)
		return;
}



/**
 * all_err - Handles all error
 * @cmd: Command passed
 * @status: Exit status
 *
 */
void all_err(char *cmd, int status)
{
	if (status == 1)
	{
		write(STDERR_FILENO, "Couldn't write\n", 15);
		exit(status);
	}
	if (status == 2)
	{
		free(cmd);
		free_arrcmd(environ);
		write(STDERR_FILENO, "\n", 1);
		exit(status);
	}
}
