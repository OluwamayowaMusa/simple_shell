#include "shell.h"

/**
 * path_array - Get arrays of path
 * @ptr_env: Pointer to environment variable
 * @arr: Pointer to array of path
 *
 */
void path_array(char **ptr_env, char ***arr)
{
	char *str, *tmp;
	int index, res;

	for (index = 0; ptr_env[index]; index++)
	{
		res = _strcmp(ptr_env[index], "PATH");
		if (res == 0)
			break;
	}
	str = _strdup(ptr_env[index]);
	tmp = strtok(str, "=");
	tmp = strtok(NULL, "=");
	(*arr) = get_path(tmp);
	if ((*arr) == NULL)
		return;
	free(str);
	str = NULL;
}


/**
 * check_file_exe - Check if file exist and is executable
 * @str: File path
 *
 * Return: 1 - If found and executable
 *         2 - if found only
 *        -1 - Otherwise
 */
int check_file_exe(char *str)
{
	int f_exist, f_exe;

	f_exist = access(str, F_0K);
	if (f_exist == 0)
	{
		f_exe = access(str, X_OK);
		if (f_exe == 0)
			return (1);
		return (2);
	}
	return (-1);
}


/**
 * env_check - Get path array
 * @envPtr: Pointer to environment varibales
 * @cmd: Command passed
 *
 * Return: Path containing command
 *
 */
char *env_check(char **envPtr, char *cmd)
{
	char **path_arr = NULL, *temp = NULL, *path = NULL;
	int index, dirLen, cmdLen, f_exist, f_exe, inx = 0;

	path_array(envPtr, &path_arr);
	temp = strtok(cmd, " ");
	cmdLen = _strlen(temp);
	for (index = 0; path_arr[index]; index++, inx = 0)
	{
		dirLen = _strlen(path_arr[index]);
		path = malloc(sizeof(char) * (dirLen + cmdLen + 2));
		if (path == NULL)
			return (NULL);
		while (inx < dirLen)
		{
			path[inx] = path_arr[index][inx];
			inx++;
		}
		path[inx] = '/';
		inx = 0;
		while (inx < cmdLen)
		{
			path[inx + dirLen + 1] = temp[inx];
			inx++;
		}
		path[inx + dirLen + 1] = '\0';
		f_exist = access(path, F_OK);
		if (f_exist == 0)
		{
			f_exe = access(path, X_OK);
			if (f_exe == 0)
			{
				free_arrcmd(path_arr);
				return (path);
			}
			free_arrcmd(path_arr);
			free(path);
			return ("NOT EXECUTABLE");
		}
		free(path);
		path = NULL;
	}
	free_arrcmd(path_arr);
	return (NULL);
}
