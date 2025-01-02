#include "simple_shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	if (argc > 0)
	{
		simple_shell(argv[0]);
	}
	else
	{
		simple_shell("hsh");
	}
	return (0);
}
