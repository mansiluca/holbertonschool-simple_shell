#include "simple_shell.h"

/**
 * parse_command - Locate and execute a command
 * @args: Pointer to arguments structure
 * @argc: Argument count
 *
 * Return: Exit status
 */

char **parse_command(arguments_t *args, int *argc)
{
	char *tmp_copy, *token, **argv;
	int count, i;

	*argc = 0;
	count = 0;
	tmp_copy = strdup(args->command);
	if (!tmp_copy)
		return (NULL);

	token = strtok(tmp_copy, " ");
	while (token)
	{
		count++;
		token = strtok(NULL, " ");
	}
	argv = malloc((count + 1) * sizeof(char *));
	if (!argv)
	{
		free(tmp_copy);
		return (NULL);
	}
	strcpy(tmp_copy, args->command);
	token = strtok(tmp_copy, " ");
	for (i = 0; i < count; i++)
	{
		argv[i] = strdup(token);
		token = strtok(NULL, " ");
	}
	argv[count] = NULL;
	*argc = count;
	free(tmp_copy);
	return (argv);
}

/**
 * free_args - Libère un tableau de chaînes de caractères
 * @argv: Le tableau de chaînes
 * @argc: Le nombre d'éléments dans argv
 */
void free_args(char **argv, int argc)
{
	int i;

	for (i = 0; i < argc; i++)
		free(argv[i]);
	free(argv);
}

/**
 * execute_command - Localise et exécute une commande
 * @args: Pointeur sur la structure d'arguments
 *
 * Return: Code de sortie du processus enfant
 */
int execute_command(arguments_t *args)
{
	pid_t pid;
	int status, ret, argc;
	char *cmd_path, **argv;

	argv = parse_command(args, &argc);
	if (!argv)
		return (EXIT_FAILURE);

	cmd_path = find_command(argv[0]);
	if (!cmd_path)
	{
		print_error(args, "not found");
		free_args(argv, argc);
		return (127);
	}
	pid = fork();
	if (pid == -1)
	{
		perror(args->name);
		free(cmd_path);
		free_args(argv, argc);
		return (EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(cmd_path, argv, args->env);
		perror(args->name);
		free(cmd_path);
		free_args(argv, argc);
		_exit(126);
	}
	else
		wait(&status);

	free(cmd_path);
	ret = WEXITSTATUS(status);
	free_args(argv, argc);
	return (ret);
}
