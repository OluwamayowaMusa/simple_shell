#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * main - working with pipe system call
 *
 * Return: 0
 */
int main(void)
{
	ssize_t charsWritten, charsRead;
	int fd[2];/*fd[0] - read, fd[1] - read*/
	int res, id, x, y;

	res = pipe(fd);
	if (res == -1)
	{
		dprintf(2, "Error\n");
		exit(1);
	}
	id = fork(); /* Creating a child process to write to kernel*/
	if (id == -1)
	{
		dprintf(2, "Error creating a child process\n");
		exit(2);
	}
	if (id == 0)
	{
		close(fd[0]);
		printf("Enter a number: ");
		scanf("%d", &x);
		charsWritten = write(fd[1], &x, sizeof(int));
		if (charsWritten == -1)
		{
			dprintf(2, "Error while writing\n");
			exit(3);
		}
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		wait(NULL);
		charsRead = read(fd[0], &y, sizeof(int));
		if (charsRead == -1)
		{
			dprintf(2, "Error while reading\n");
			exit(4);
		}
		close(fd[0]);
		printf("Got %d from the child process\n", y);
	}
}
