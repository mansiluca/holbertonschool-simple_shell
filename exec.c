#include "simple_shell.h"

/**
 * execute_command - execute a command
 * @argv: arguments to command
 */

void execute_command(char **argv)
{
	pid_t pid;
	int status;
	char *full_path;

	full_path = find_command(argv[0]);
	if (!full_path)
	{
		fprintf(stderr, "%s: Command not found", argv[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		free(full_path);
		return;
	}
	else if (pid == 0)
	{
		if (execve(full_path, argv, environ) == -1)
		{
			perror(argv[0]);
            free(full_path);
            exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	free(full_path);
}
