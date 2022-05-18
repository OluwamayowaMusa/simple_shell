#include "shell.h"

/**
 * main - Working with environment variables
 * @argc: Argument count
 * @argv: Argument vector
 * @envp: Enviroment variales
 *
 * Return: 0
 */
int main(int argc, char *argv[], char *envp[])
{
	char *s;
	s = env_check(envp, "        ls -l");
	if (s != NULL)
	{
		printf("%s\n", s);
	}
	else
	{
		printf("Error\n");
	}
	return (0);
}
