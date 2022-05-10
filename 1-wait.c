#include <stdio.h>
#include <unistd.h>

/**
 * main - Understanding the wait system call
 *
 *
 * Return: 0
 */
int main(void)
{
	int id = fork();
	int n, i;

	if (id == 0)
		n = 1;
	else
		n = 6;

	for(i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	printf("\n");

	return (0);
}
