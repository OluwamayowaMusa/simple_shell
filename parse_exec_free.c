#include "shell.h"

/**
 * parse_exec_free - Get commands, execute commands, free memory
 * @cmd: Commad passed
 * @ptr: Name of program
 * @env: Environment variables
 * @ptr_num: Pointer to error count
 *
 */
void parse_exec_free(char *cmd, char *ptr, char **env, int *ptr_num)
{
	char **arr_cmd, *path_cmd, *s, *temp;
	int ctrl;

	s = _strdup(cmd);
	temp = strtok(s, " ");
	if (temp[0] == '/')
	{
		arr_cmd = get_cmd(cmd);
		ctrl = check_file_exe1(arr_cmd[0]);
		if (ctrl == 1)
			_execute(arr_cmd, ptr, env, ptr_num);
		else if (ctrl == 2)
			access_err(ptr, arr_cmd[0]);
		else if (ctrl == -1)
			cmd_error(ptr, arr_cmd[0], ptr_num);
		free_arrcmd(arr_cmd);
		free(s);
	}
	else
	{
		arr_cmd = get_cmd(cmd);
		path_cmd = env_check(env, arr_cmd[0]);
		if (path_cmd == NULL)
		{
			cmd_error(ptr, arr_cmd[0], ptr_num);
		}
		else if (_strcmp1(path_cmd, "NOT EXECUTABLE") == 0)
		{
			access_err(ptr, arr_cmd[0]);
		}
		else
		{
			_execute_path(path_cmd, arr_cmd, ptr, env, ptr_num);
			free(path_cmd);
		}
		free_arrcmd(arr_cmd);
		free(s);
	}
	s = NULL;
}
