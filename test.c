#include "shell.h"

/**
 * main - test function
 *
 * Return: 0
 */
int main(void)
{
	char *argv[] = {"/bin/ls", NULL};

	printf("Before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
			perror(argv[0]);
	printf("After execve\n");
}
