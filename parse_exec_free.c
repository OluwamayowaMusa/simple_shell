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

	s = _strdup(cmd);
	temp = strtok(s, " ");
	if (temp[0] == '/')
	{
		arr_cmd = get_cmd(cmd);
		_execute(arr_cmd, ptr, env, ptr_num);
		free_arrcmd(arr_cmd);
		free(s);
	}
	else
	{
		arr_cmd = get_cmd(cmd);
		path_cmd = env_check(env, arr_cmd[0]);
		if (path_cmd == NULL)
		{
			(*ptr_num)++;
			free(s);
			cmd_error(ptr, arr_cmd[0], ptr_num);
			free_arrcmd(arr_cmd);
			return;
		}
		if (_strcmp1(path_cmd, "NOT EXECUTABLE") == 0)
		{
			free(s);
			write(STDERR_FILENO, ptr, _strlen(ptr));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, cmd, _strlen(cmd));
			write(STDERR_FILENO, ": Permission denied\n", 20);
			return;
		}
		_execute_path(path_cmd, arr_cmd, ptr, env, ptr_num);
		free_arrcmd(arr_cmd);
		free(path_cmd);
		free(s);
	}
	s = NULL;
}
