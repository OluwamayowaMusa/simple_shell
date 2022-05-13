#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>

/**
 * main - calling fork multiple times
 *
 * Return: 0
 */
int main(void)
{
	int id1 = fork();
	int id2 = fork();

	if (id1 == 0)
	{
		if (id2 == 0)
		{
			printf("I am a child of the first child of the parent: Z\n");
		}
		else
		{
			printf("I am the first child of the parent process: X\n");
		}
	}
	else
	{
		if (id2 == 0)
		{
			printf("I am the second child of the parent process: Y\n");
		}
		else
		{
			printf("I am the Parent process\n");
		}
	}
	while (wait(NULL) != -1 || errno != ECHILD)
	{
		printf("waited for a child to finish\n");
	}
}
