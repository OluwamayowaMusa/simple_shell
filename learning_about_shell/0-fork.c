#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

/**
 * main - Learning fork system call
 *
 * Return: 0
 */
int main(void)
{
	int id = fork();
	
	if (id != 0)
		fork();
	printf("Hello World\n");

	return (0);
}
