#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _getline - Get the string input
 * @str: Pointer to the string
 * @size: Pointer to the size of the string
 * @fd: File descriptor
 *
 * Return: Number of characters read
 */
ssize_t _getline(char **str, size_t *n, const int fd)
{
	ssize_t charsRead, chars;
	char buf[1024];

	if (fd == -1)
		return (-1);
	charsRead = read(fd, buf, 1024);
	if (charsRead == -1)
		return (-1);
	chars = charsRead;
	while (charsRead > 0)
	{
		charsRead = read(fd, buf, 1024);
		chars += charsRead;
	}
	if (chars != (ssize_t)*n)
	{
		free(*str);
		*str = malloc(sizeof(char) * chars);
		if (*str == NULL)
		{
			return (-1);
		}
	}
	charsRead = read(fd, *str, chars);
	write(1, *str, charsRead);

	return  (charsRead);
}

/**
 * main - test Function
 *
 * Return: 0
 */
int main(void)
{
	char *s;
	size_t n = 50;
	s = malloc(sizeof(char) * n);
	if (s == NULL)
		return (-1);
	printf("~$ ");

	fgets(s, 50, fopen("test.txt", "r"));
	
	_getline(&s, &n, 0);
}
