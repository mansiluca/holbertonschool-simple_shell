#include "simple_shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * find_command - find a command in the PATH
 * @command: command to find
 * Return: full path to command
 */

char *find_command(const char *command)
{
	char *path = _getenv("PATH");
	char *path_copy;
	char *dir;
	struct stat st;
	char *full_path;

	if (command[0] == '/')
	{
		if (stat(command, &st) == 0)
		{
			return (strdup(command));
		}
		return (NULL);
	}
	if (!path)
		return (NULL);
	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);
	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
