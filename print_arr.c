#include "shell.h"

/**
 * print_arr - Print array
 * @arr: Array
 *
 */
void print_arr(char **arr)
{
	int index;

	for (index = 0; arr[index]; index++)
		printf("%s\n", arr[index]);
}
