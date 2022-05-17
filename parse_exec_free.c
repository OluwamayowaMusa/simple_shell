#include "shell.h"

/**
 * parse_exec_free - Get commands, execute commands, free memory
 * @cmd: Commad passed
 *
 */
void parse_exec_free(char *cmd)
{
	char **arr_cmd;

	arr_cmd = get_cmd(cmd);
	_execute(arr_cmd);
	free_arrcmd(arr_cmd);
}
