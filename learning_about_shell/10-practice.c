#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>

/**
 * main - practicing pipes
 *
 * Return: 0
 */
int main(void)
{
	int fd[2]; /* File descriptors */
	int res, id, data, dataRead, final;

	res = pipe(fd);
	if (res == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		data = 5;
		if (write(fd[1], &data, sizeof(data)) == -1)
			return (3);
	}
	else
	{
		if (read(fd[0], &dataRead, sizeof(int)) == -1)
		{
			printf("----here\n");
			return (4);
		}
		dataRead = dataRead * 4;
		if (write(fd[1], &dataRead, sizeof(int)) == -1)
			return (5);
		close(fd[1]);
		close(fd[0]);
	}
	if (id == 0)
	{
		sleep(0.1);
		close(fd[1]);
		if (read(fd[0], &final, sizeof(final)) == -1)
			return (6);
		printf("The final number is %d\n", final);
		close(fd[0]);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
