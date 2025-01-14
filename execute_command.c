#include "simple_shell.h"

/**
 * execute_command - Locate and execute a command
 * @args: Pointer to arguments structure
 *
 * Return: Exit status
 */
int execute_command(arguments_t *args)
{
	pid_t pid;
	int status;
	char *cmd_path = find_command(args->command);
	char *argv[2];

	if (!cmd_path)
	{
		print_error(args, "not found");
		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror(args->name);
		free(cmd_path);
		return (EXIT_FAILURE);
	}

	if (pid == 0)
	{
		argv[0] = cmd_path;
		argv[1] = NULL;
		execve(cmd_path, argv, args->env);
		perror(args->name);
		free(cmd_path);
		_exit(126);
	}
	else
	{
		wait(&status);
	}

	free(cmd_path);
	return (WEXITSTATUS(status));
}
