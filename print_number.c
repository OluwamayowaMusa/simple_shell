#include "shell.h"

/**
 * print_number - Write number to file stream
 * @num: Number passed
 *
 */
void print_number(int num)
{
	char c;

	if (num / 10 > 0)
		print_number(num / 10);
	c = num % 10 + '0';
	_putchar(c);
}
