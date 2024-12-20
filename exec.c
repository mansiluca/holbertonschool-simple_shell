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
	static int count = 1;

	full_path = find_command(argv[0]);
	if (!full_path)
	{
		fprintf(stderr, "line %d: %s: command not found\n",
			count, argv[0]);
		count++;
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror(argv[0]);
		free(full_path);
		count++;
		return;
	}
	else if (pid == 0)
	{
		if (execve(full_path, argv, environ) == -1)
		{
			perror(argv[0]);
			free(full_path);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	free(full_path);
	count++;
}
