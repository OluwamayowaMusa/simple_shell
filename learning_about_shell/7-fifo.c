#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

/**
 * main - working with FIFO
 *
 * Return: 0
 */
int main(void)
{
	int res = mkfifo("myfifo1", 0777);
	int fd, data = 87, numWritten;

	if (res == -1)
	{
		if (errno != EEXIST)
		{
			printf("Could not create FIFO file\n");
			return (1);
		}
	}
	printf("Opening\n");

	fd = open("myfifo1", O_RDWR);
	if (fd == -1)
		return (-1);
	printf("Writing\n");
	numWritten = write(fd, &data, sizeof(int));
	if (numWritten == -1)
		return (-1);
	printf("Closed\n");
	close(fd);

	return (0);
}
