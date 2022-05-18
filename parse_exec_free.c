#include "shell.h"

/**
 * parse_exec_free - Get commands, execute commands, free memory
 * @cmd: Commad passed
 * @ptr: Name of program
 * @env: Environment variables
 *
 */
void parse_exec_free(char *cmd, char *ptr, char **env)
{
	char **arr_cmd;

	if (cmd[0] != '/')
	{
		arr_cmd = get_cmd(cmd);
		_execute(arr_cmd, ptr, env);
		free_arrcmd(arr_cmd);
	}
	else
	{

	}
}
