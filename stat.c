#include "simple_shell.h"

/**
 * check_file_exists - checks if a file exists
 * @filepath: path to file
 * Return: 1 if file exists, 0 if not
 */

int check_file_exists(const char *filepath)
{
	struct stat st;

	return (stat(filepath, &st) == 0);
}

