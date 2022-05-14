#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * main - writing to fifo
 *
 * Return: 0
 *
 */
int main(void)
{
	ssize_t numWritten, numRead;
	int arr[] = {1, 2, 4, 5, 8, 9, 10};
	int fd, sum;

	fd = open("sum", O_WRONLY);
	if (fd == -1)
	{
		printf("Unable to open FIFO\n");
		exit(97);
	}
	numWritten = write(fd, arr, sizeof(arr));
	if (numWritten == -1)
	{
		printf("Unable to write to FIFO\n");
		exit(98);
	}
	printf("Written successfully\n");

	close(fd);

	fd = open("sum", O_RDONLY);
	if (fd == -1)
	{
		printf("Unable to open after writing\n");
		exit(102);
	}
	numRead = read(fd, &sum, sizeof(int));
	if (numRead == -1)
	{
		printf("Unable to read sum\n");
		exit(103);
	}
	printf("Sum of numbers: %d\n", sum);
	close(fd);
	return (0);
}

