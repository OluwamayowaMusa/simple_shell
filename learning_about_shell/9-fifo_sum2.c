#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * main - reading from FIFO
 *
 * Return: 0
 */
int main(void)
{
	ssize_t numRead, numWritten;
	int arr[7];
	int fd, index, sum = 0;

	fd = open("sum", O_RDONLY);
	if (fd == -1)
	{
		printf("Unable to open from FIFO");
		exit(99);
	}
	numRead = read(fd, arr, sizeof(arr));
	if (numRead == -1)
	{
		printf("Unable to read from FIFO\n");
		exit(99);
	}
	printf("Read successfully\n");
	for (index = 0; index < 7; index++)
	{
		sum += arr[index];
	}

	close(fd);

	fd = open("sum", O_WRONLY);
	if (fd == -1)
	{
		printf("Unable to open FIFO after reading\n");
		exit(100);
	}
	numWritten = write(fd, &sum, sizeof(sum));
	if (numWritten == -1)
	{
		printf("Unable to write sum\n");
		exit(101);
	}
	close(fd);
	return (0);
}
