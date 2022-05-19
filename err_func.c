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