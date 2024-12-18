#include "simple_shell.h"

/**
 * print_args - prints arguments
 * @argc: argument count
 * @argv: argument vector
 */

void print_args(int argc, char **argv)
{
	int i = 0;

	for (; i < argc; i++)
	{
		printf("Argument %d: %s", i, argv[i]);
	}
}

