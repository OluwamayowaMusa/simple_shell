#include "shell.h"

/**
 * print_env - Print Environment variables
 * @ptr: pointer to environment variables
 * @str: Command passed
 * @ptr_err: Pointer to error count
 *
 */
void print_env(char **ptr, char *str, int *ptr_err)
{
	int i;

	(*ptr_err)++;
	for (i = 0; ptr[i]; i++)
	{
		write(STDOUT_FILENO, ptr[i], _strlen(ptr[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free(str);
}

/**
 * _setenv - Initalize a new environment variable or modify existing one
 * @cmd: Command passed
 * @ptr_err: Pointer to error counter
 *
 * Return: 0 - On success
 *        -1 - On Failure
 */
int _setenv(char *cmd, int *ptr_err)
{
	char **cmd_arg = NULL, *new_value = NULL, **env_name, **new_environ;
	int size;

	if (no_arg(cmd, " ") != 3)
		return (-1);
	cmd_arg = get_cmd(cmd);
	if (cmd_arg == NULL)
		return (-1);
	new_value = malloc(sizeof(char) *(_strlen(cmd_arg[1]
						+ _strlen(cmd_arg[2]) + 2)));
	if (new_value == NULL)
		return (-1);
	_strcpy(new_value, cmd_arg[1]);
	_strcat(new_value, "=");
	_strcat(new_value, cmd_arg[2]);
	env_name = _get_env(cmd_arg[1]);
	if (env_name)
	{
		free(*env_name);
		*env_name = malloc(sizeof(char) * (_strlen(new_value) + 1));
		if ((*env_name) == NULL)
			return (-1);
		_strcpy(*env_name, new_value);
		(*ptr_err)++;
		free(cmd);
		return (0);
	}
	for (size = 0; environ[size]; size++);
	new_environ = malloc(sizeof(char *) * (size + 2));
	if (new_environ == NULL)
		return (-1);
	copy_env(new_environ);
	new_environ[size] = malloc(sizeof(char) * (_strlen(new_value) + 1));
	if (new_environ[size] == NULL)
		return (-1);
	_strcpy(new_environ[size], new_value);
	environ = new_environ;
	environ[size + 1] = NULL;
	(*ptr_err)++;
	free(cmd);
	return (0);
}
