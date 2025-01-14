#include "simple_shell.h"

/**
 * find_command - Locate a command in the PATH
 * @command: Command to locate
 *
 * Return: Full path to command or NULL
 */
char *find_command(const char *command)
{
	char *path = getenv("PATH");
	char *token, *full_path, *path_copy;

	if (!path || command[0] == '/')
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		return (NULL);
	}

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
