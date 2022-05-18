#include "shell.h"

/**
 * print_arr - Print arrays of strings
 * @ptr: pointer to array of strings
 */
void print_arr(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		printf("%s\n", ptr[i]);

}
