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
 * @last_status: Last command exit status
 */
typedef struct arguments
{
	char *name;
	char *command;
	char **env;
	int cmd_count;
	int last_status;
} arguments_t;

extern char **environ;
int interpreter(arguments_t *args);
int execute_command(arguments_t *args);
void print_error(arguments_t *args, const char *msg);
char *find_command(const char *command);
int handle_builtin(arguments_t *args);
char **parse_command(arguments_t *args, int *argc);
void free_args(char **argv, int argc);
char *_getenv(const char *name);
size_t _strspn(const char *s, const char *accept);
char *_strpbrk(const char *s, const char *accept);
char *_strtok_r(char *s, const char *delim, char **save_ptr);

#endif
