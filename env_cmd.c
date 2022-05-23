#include "shell.h"

/**
 * print_env - Print Environment variables
 * @ptr: pointer to environment variables
 * @ptr_err: Pointer to error count
 *
 */
void print_env(char **ptr, int *ptr_err)
{
	int i;

	(*ptr_err)++;
	for (i = 0; ptr[i]; i++)
	{
		write(STDOUT_FILENO, ptr[i], _strlen(ptr[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
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

	(*ptr_err)++;
	if (no_arg(cmd, " ") != 3)
		return (-1);
	cmd_arg = get_cmd(cmd);
	if (cmd_arg == NULL)
		return (-1);
	new_value = malloc(sizeof(char) * (_strlen(cmd_arg[1])
						+ _strlen(cmd_arg[2]) + 2));
	if (new_value == NULL)
		return (-1);
	_strcpy(new_value, cmd_arg[1]), _strcat(new_value, "=");
	_strcat(new_value, cmd_arg[2]);
	env_name = _get_env(cmd_arg[1]);
	if (env_name)
	{
		free(*env_name);
		*env_name = malloc(sizeof(char) * (_strlen(new_value) + 1));
		if ((*env_name) == NULL)
			return (-1);
		_strcpy(*env_name, new_value);
		free_arrcmd(cmd_arg), free(new_value);
		return (0);
	}
	free_arrcmd(cmd_arg);
	for (size = 0; environ[size]; size++)
		;
	new_environ = malloc(sizeof(char *) * (size + 2));
	if (new_environ == NULL)
		return (-1);
	copy_env(new_environ);
	new_environ[size] = malloc(sizeof(char) * (_strlen(new_value) + 1));
	if (new_environ[size] == NULL)
		return (-1);
	_strcpy(new_environ[size], new_value);
	free_arrcmd(environ), free(new_value);
	environ = new_environ, environ[size + 1] = NULL;
	return (0);
}


/**
 * _unsetenv - Remove an environment varibale
 * @cmd: Command passed
 * @ptr_err: Pointer to error counter
 *
 * Return: 0 - On success
 *        -1 - On failure
 */
int _unsetenv(char *cmd, int *ptr_err)
{
	char **cmd_arg = NULL, **env_var, **new;
	int size;

	(*ptr_err)++;
	if (no_arg(cmd, " ") != 2)
		return (-1);
	cmd_arg = get_cmd(cmd);
	if (cmd_arg == NULL)
		return (-1);
	env_var = _get_env(cmd_arg[1]);
	free_arrcmd(cmd_arg);
	if (env_var)
	{
		free(*env_var);
		*env_var = malloc(sizeof(char) * (_strlen("skip") + 1));
		if ((*env_var) == NULL)
			return (-1);
		_strcpy(*env_var, "skip");
	}
	if (!env_var)
		return (0);
	for (size = 0; environ[size]; size++)
		;
	new = malloc(sizeof(char *) * size);
	if (new == NULL)
		return (-1);
	arrange_env(new);
	new[size - 1] = NULL;
	free_arrcmd(environ);
	environ = new;
	return (0);
}

/**
 * arrange_env - Rearrange environment variables
 * @ptr: Pointer to variable to contain environment variables
 *
 */
void arrange_env(char **ptr)
{
	int index, i;

	for (index = 0, i = 0; environ[index]; index++, i++)
	{
		if (_strcmp1(environ[index], "skip") == 0)
		{
			i--;
			continue;
		}
		ptr[i] = malloc(sizeof(char) * (_strlen(environ[index]) + 1));
		if (ptr[i] == NULL)
		{
			while (i > -1)
			{
				i--;
				free(ptr[i]);
			}
			free(ptr);
			return;
		}
		_strcpy(ptr[i], environ[index]);
	}
}
