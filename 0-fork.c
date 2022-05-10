#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - Understanding system calls
 *
 * Return: 0
 */

int main(void)
{
	int id = fork();

	if (id != 0)
	{
		fork();
	}

	printf("Hello World\n");
	return (0);
}
