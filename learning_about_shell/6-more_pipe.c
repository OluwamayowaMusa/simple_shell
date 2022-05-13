#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - working with pipe
 *
 * Return: 0
 */
int main(void)
{
	ssize_t charsWritten, charsRead;
	int arr[] = {10, 1, 2, 4, 5, 2, 3, 8}, fd[2], childSum, totalSum;
	int arrSize = sizeof(arr) / sizeof(int);
	int res, id, startIndex, endIndex, index, sum = 0;

	res = pipe(fd);
	if (res == -1)
	{
		return (1);
	}
	id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		startIndex = 0;
		endIndex = arrSize / 2;
	}
	else
	{
		startIndex = arrSize / 2;
		endIndex = arrSize;
	}
	for (index = startIndex; index < endIndex; index++)
	{
		sum += arr[index];
	}
	printf("Calculated partial sum: %d\n", sum);
	if (id == 0)
	{
		close(fd[0]);
		charsWritten = write(fd[1], &sum, sizeof(int));
		if (charsWritten == -1)
			return (-1);
		close(fd[1]);

	}
	else
	{
		wait(NULL);
		close(fd[1]);
		charsRead = read(fd[0], &childSum, sizeof(int));
		if (charsRead == -1)
			return (-1);
		totalSum = sum + childSum;
		printf("Total sum: %d\n", totalSum);
	}

	return (0);
}
