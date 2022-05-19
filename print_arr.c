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
		printf("%s\n", ptr[i]);
	free(str);
}
