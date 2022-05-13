#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * main - understanding wait
 *
 * Return: 0
 */
int main(void)
{
	int id = fork();
	int n, i;

	if (id == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}
	if (id != 0)
		wait(NULL);
	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	if (id != 0)
	{
		putchar(10);
	}

	return (0);
}
