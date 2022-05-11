#include <stdio.h>

/**
 * main - Prints all the arguments passed through the main function
 * @argc: Argument count
 * @argv: Argument Vector
 *
 * Return: 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	int i;

	for (i = 1; argv[i]; i++)
	{
		printf("%s ", argv[i]);
	}
	putchar(10);
	return (0);
}
