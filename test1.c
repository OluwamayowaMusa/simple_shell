#include "shell.h"

/**
 * main - test access function
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int res, exe;
	int i = 1;

	while (argv[i])
	{
		res = access(argv[i], F_OK);
		if (res == 0)
		{
			printf("Found ");
			exe = access(argv[i], X_OK);
			if (exe == 0)
				printf(" Executable\n");
			else
				putchar(10);
		}
		else
		{
			printf("Not Found\n");
		}
		i++;
	}

	return (0);
}
