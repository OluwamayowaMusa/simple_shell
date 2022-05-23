#include "shell.h"

/**
 * _get_env - Get environment variable with variable name
 * @s: Name
 *
 * Return: Address of environment variable found
 *         NULL - othrwise
 */
char **_get_env(char *s)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (_strcmp(environ[i], s) == 0)
			return (&environ[i]);
	}
	return (NULL);
}

/**
 * copy_env - Copies the environ variable
 * @ptr_env: Pointer to variable copied to
 *
 */
void copy_env(char **ptr_env)
{
	int index;

	for (index = 0; environ[index]; index++)
	{
		ptr_env[index] = malloc(sizeof(char) * (_strlen(environ[index]) + 1));
		if (ptr_env[index] == NULL)
		{
			while (index >= 0)
			{
				index--;
				free(ptr_env[index]);
			}
			free(ptr_env);
			return;
		}
		_strcpy(ptr_env[index], environ[index]);
	}
}

/**
 * _copyenv - Copy environment vaiables
 *
 * Return: environment variables
 */
char **_copyenv(void)
{
	char **new;
	int index, size;

	for (size = 0; environ[size]; size++)
		;
	new = malloc(sizeof(char *) * (size + 1));
	if (new == NULL)
		return (NULL);
	for (index = 0; environ[index]; index++)
	{
		new[index] = malloc(sizeof(char) * _strlen(environ[index]) + 1);
		if (new[index] == NULL)
		{
			while (index >= 0)
			{
				index--;
				free(new[index]);
			}
			free(new);
			return (NULL);
		}
		_strcpy(new[index], environ[index]);
	}
	new[index] = NULL;
	return (new);
}
