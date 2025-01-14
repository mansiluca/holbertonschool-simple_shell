#include "simple_shell.h"

/**
 * interpreter - Process and execute a command
 * @args: Pointer to arguments structure
 *
 * Return: Exit status
 */
int interpreter(arguments_t *args)
{
	char *cmd;
	int status = 0;
	char *command_copy = strdup(args->command);

	if (command_copy == NULL)
		return (-1);

	cmd = strtok(command_copy, ";");
	while (cmd != NULL)
	{
		args->command = cmd;
		if (handle_builtin(args) == -1)
			status = execute_command(args);
		cmd = strtok(NULL, ";");
	}

	free(command_copy);
	return (status);
}

/**
 * handle_builtin - Handle built-in commands
 * @args: Pointer to arguments structure
 *
 * Return: Exit status
 */
int handle_builtin(arguments_t *args)
{
	int i;

	if (strncmp(args->command, "exit", 4) == 0)
	{
		int exit_code = 0;

		if (args->command[4] != '\0')
			exit_code = atoi(args->command + 5);
		exit(exit_code);
	}

	if (strcmp(args->command, "env") == 0)
	{
		for (i = 0; args->env[i]; i++)
			printf("%s\n", args->env[i]);
		return (0);
	}

	if (strncmp(args->command, "echo", 4) == 0)
	{
		printf("%s\n", args->command + 5);
		return (0);
	}

	return (-1);
}

