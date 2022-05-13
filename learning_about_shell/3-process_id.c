#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * main - understanding processes id
 *
 * Return: 0
 */
int main(void)
{
	int id = fork(), res;

	if (id == 0)
	{
		sleep(1);
	}
	res = wait(NULL);
	if (res == -1)
	{
		printf("No process to wait for\n");
	}
	else
	{
		printf("%d process done\n", res);
	}
	printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
	return (0);
}
