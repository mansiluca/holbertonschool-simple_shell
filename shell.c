#include "simple_shell.h"
#include <errno.h>

/**
 * split_command - split a command into arguments
 * @line: command to split
 * Return: array of arguments
 */

char **split_command(const char *line)
{
	char **argv = NULL;
	char *line_copy = strdup(line);
	int argc = 0;

	if (!line_copy)
	{
		perror("Error duplicating line");
		return (NULL);
	}

	argv = tokenize_line(line_copy, &argc);
	free(line_copy);

	if (!argv)
	{
		fprintf(stderr, "Error: Failed to parse command\n");
		return (NULL);
	}

	return (argv);
}

/**
 * tokenize_line - tokenize a line
 * @line_copy: copy of line
 * @argc: argument count
 * Return: array of arguments
 */

char **tokenize_line(char *line_copy, int *argc)
{
	char **argv = NULL;
	char *token = strtok(line_copy, " ");

	while (token)
	{
		argv = _realloc(argv, sizeof(char *) * (*argc),
		sizeof(char *) * (*argc + 1));
		if (!argv)
		{
			perror("Error reallocating memory");
			return (NULL);
		}
		argv[*argc] = strdup(token);
		if (!argv[*argc])
		{
			perror("Error duplicating token");
			free_argv(argv);
			return (NULL);
		}
		(*argc)++;
		token = strtok(NULL, " ");
	}

	argv = _realloc(argv, sizeof(char *) * (*argc), sizeof(char *) * (*argc + 1));
	if (!argv)
	{
		perror("Error reallocating memory");
		return (NULL);
	}
	argv[*argc] = NULL;

	return (argv);
}


/**
 * read_line - read a line from stdin
 * Return: pointer to line
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error reading line");
			free(line);
			return (NULL);
		}
	}
	line[strcspn(line, "\n")] = '\0';
	return (line);
}

/**
 * free_argv - free an array of strings
 * @argv: array of strings
 */

void free_argv(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
}

/**
 * simple_shell - a simple shell
 * @exec_name: name of the executable
 * Return: void
 */

void simple_shell(const char *exec_name)
{
	char *line;
	char **argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		line = read_line();
		if (!line)
			continue;
		if (strlen(line) == 0)
		{
			free(line);
			continue;
		}
		argv = split_command(line);
		free(line);
		if (!argv)
		{
			fprintf(stderr, "Error: Failed to parse command\n");
			continue;
		}
		if (argv[0] && strcmp(argv[0], "exit") == 0)
		{
			int status = EXIT_SUCCESS;
			if (argv[1] != NULL)
			{
				status = atoi(argv[1]);
			}
			free_argv(argv);
			exit(status);
		}
		if (strcmp(argv[0], "env") == 0)
		{
			env_command();
			free_argv(argv);
			continue;
		}
		execute_command(argv, exec_name);
		free_argv(argv);
	}
}
