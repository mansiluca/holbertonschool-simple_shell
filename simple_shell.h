#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * struct arguments - Structure for shell arguments
 * @name: Shell program name
 * @command: Command string
 * @env: Environment variables
 * @cmd_count: Command count
 */
typedef struct arguments
{
	char *name;
	char *command;
	char **env;
	int cmd_count;
} arguments_t;

int interpreter(arguments_t *args);
int execute_command(arguments_t *args);
void print_error(arguments_t *args, const char *msg);
char *find_command(const char *command);
int handle_builtin(arguments_t *args);

#endif
