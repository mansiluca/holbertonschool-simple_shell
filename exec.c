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
		fprintf(stderr, "%s: Command not found\n", argv[0]);
	}
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
		}
		else if (pid == 0)
		{
			if (execve(full_path, argv, NULL) == -1)
			{
				perror("Error executing command");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
		free(full_path);
	}
}
