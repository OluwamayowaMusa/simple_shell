#include "shell.h"

/**
 * no_arg - Get number of arguments
 * @str: String passed
 * @delim: Delimiter
 *
 * Return: Number of arguments
 */
int no_arg(char *str, char *delim)
{
	char *s;
	char *s1 = _strdup(str);
	int i = 0;

	s = strtok(s1, delim);
	while (s != NULL)
	{
		s = strtok(NULL, delim);
		i++;
	}
	free(s1);
	s1 = NULL;
	return (i);
}


/**
 * arr_cmd_size - Get the size of array od strings
 * @ptrCmd: Pointer to array of commands and arguments
 * @argNum: Number of arguments
 * @str: command string
 */
void arr_cmd_size(char ***ptrCmd, int argNum, char *str)
{
	char *s1 = _strdup(str), *tmp;
	int index;

	tmp = strtok(s1, " ");
	for (index = 0; index < argNum - 1 && tmp != NULL; index++)
	{
		*((*ptrCmd) + index) = malloc(sizeof(char) * (_strlen(tmp) + 1));
		if (*((*ptrCmd) + index) == NULL)
		{
			while (index > -1)
			{
				index--;
				free((*ptrCmd)[index]);
			}
			free(*ptrCmd);
			return;
		}
		tmp = strtok(NULL, " ");
	}
	free(s1);
	s1 = NULL;
}


/**
 * get_cmd - Get the array of commands and arguments
 * @cmd_ptr: Pointer to the input string
 *
 * Return: Array of stringd
 */
char **get_cmd(char *cmd_ptr)
{
	char *s = NULL, *temp, **arr = NULL;
	int len, index, index2;

	s = _strdup(cmd_ptr);
	len = no_arg(cmd_ptr, " ") + 1;
	arr = (char **)malloc(sizeof(char *) * len);
	if (arr == NULL)
		return (NULL);
	arr_cmd_size(&arr, len, cmd_ptr);
	temp = strtok(s, " ");
	for (index = 0; index < len - 1 && temp != NULL; index++)
	{
		for (index2 = 0; temp[index2]; index2++)
		{
			*(*(arr + index) + index2) = temp[index2];
		}
		*(*(arr + index) + index2) = '\0';
		temp = strtok(NULL, " ");
	}
	*(arr + index) = NULL;
	free(s);
	s = NULL;
	return (arr);
}
