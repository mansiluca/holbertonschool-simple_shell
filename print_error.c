#include "simple_shell.h"

/**
 * print_error - Print an error message
 * @args: Pointer to arguments structure
 * @msg: Error message to print
 */
void print_error(arguments_t *args, const char *msg)
{
	const char *error_msg = msg;

	if (strchr(args->command, '/') != NULL)
	{
		error_msg = "No such file or directory";
	}

	fprintf(stderr, "%s: %d: %s: %s\n",
		args->name, args->cmd_count, args->command, error_msg);
}
