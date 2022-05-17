#include "shell.h"

/**
 * free_arrcmd - Free allocated memory for array of commads
 * @arrCmd: Array of command and arguments
 */
void free_arrcmd(char **arrCmd)
{
	int index;

	for (index = 0; arrCmd[index]; index++)
	{
		free(arrCmd[index]);
		arrCmd[index] = NULL;
	}
	free(arrCmd[index]);
	arrCmd[index] = NULL;
	free(arrCmd);
	arrCmd = NULL;
}
