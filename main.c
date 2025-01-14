#include "simple_shell.h"

/**
 * main - Entry point of the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment variables
 *
 * Return: Exit status
 */
int main(int argc, char **argv, char **env)
{
	arguments_t args;
	int status = 0;
	size_t len = 0;

	(void)argc;

	args.name = argv[0];
	args.env = env;
	args.command = NULL;
	args.cmd_count = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		if (getline(&args.command, &len, stdin) == -1)
		{
			free(args.command);
			break;
		}

		if (args.command[0] == '\n')
		{
			free(args.command);
			args.command = NULL;
			continue;
		}

		args.command = strtok(args.command, "\n");
		args.cmd_count++;
		status = interpreter(&args);
		free(args.command);
		args.command = NULL;

		if (status == EXIT_FAILURE)
			break;
	}

	return (status);
}
