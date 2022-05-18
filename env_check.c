#include "shell.h"

/**
 * path_arr - Get arrays of path
 * @ptr_env: Pointer to environment variable
 */
void path_arr(char **ptr_env, char ***arr)
{
	int index, res;

	for (index = 0; ptr_env[index]; index++)
	{
		res = _strcmp(&ptr_env[index], "PATH");
		if (res == 0)
			break;
	}
	*arr = get_path(ptr_env[index]);
	if ((*arr) == NULL)
		return;
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
	char **path_arr, *temp, *str, *path;
	int res, index, dirLen, cmdLen, f_exist, f_exe, inx;

	for (index = 0; envPtr[index]; index++)
	{
		res = _strcmp(&envPtr[index], "PATH");
		if (res == 0)
			break;
	}
	path_arr = get_path(envPtr[index]);
	if (path_arr == NULL)
		return (NULL);
	str = _strdup(cmd);
	temp = strtok(str, " ");
	cmdLen = _strlen(temp);
	for (index = 0; path_arr[index]; index++)
	{
		dirLen = _strlen(path_arr[index]);
		path = malloc(sizeof(char) * (dirLen + cmdLen + 2));
		if (path == NULL)
			return (NULL);
		inx = 0;
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
		printf("%s\n", path);
		f_exist = access(path, F_OK);
		if (f_exist == 0)
		{
			f_exe = access(path, X_OK);
			if (f_exe == 0)
				return (path);
			free(path);
			return ("NOT EXECUTABLE");
		}
		free(path);
		path = NULL;
	}
	free(str);
	str = NULL;
	return (NULL);
}
