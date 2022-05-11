#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - Get the process ID of the parent of the calling process
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t parent_pid;

	parent_pid = getppid();
	printf("%u\n", parent_pid);
	return (0);
}
