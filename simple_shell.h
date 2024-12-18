#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

/**
 * struct my_pid - linked list of pids
 * @pid: pid
 * @next: pointer to next node
 * Description: singly linked list node structure
 * for storing pids
 */

typedef struct my_pid
{
	pid_t pid;
	struct my_pid *next;
} my_pid;

void print_pid(void);
void print_ppid(void);
void print_args(int argc, char **argv);
void fork_example(void);
void wait_example(void);
int check_file_exists(const char *filepath);
char *_getenv(const char *name);
void simple_shell(void);
char *_strtok(char *str, const char *delim);
char **split_command(const char *line);
char *find_command(const char *command);
void free_argv(char **argv);
char *read_line(void);
void execute_command(char **argv);
char prompt(void);
void env_command(void);
char **tokenize_line(char *line_copy, int *argc);

#endif
