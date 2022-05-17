#include "shell.h"

/**
 * _strdup - Copies a string to an allocated space in the memory
 * @str: String passed
 *
 * Return: Pointer to duplicated string
 *         NULL if failed
 */
char *_strdup(char *str)
{
	char *ptr = NULL;
	int i;

	if (str == NULL)
		return (NULL);
	ptr = malloc(sizeof(char) * (_strlen(str) + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		ptr[i] = str[i];
	ptr[i] = '\0';

	return (ptr);
}
