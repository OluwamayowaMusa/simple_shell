#include <stdio.h>
#include <unistd.h>

/**
 * main - executing commands
 *
 * Return: 0
 */
int main(void)
{
	char *argv[] = {"/bin/ls", NULL};

	printf("Before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("ERROR:");
	}
	printf("After Execve\n");
	return (0);
}
