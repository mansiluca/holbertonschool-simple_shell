#include "simple_shell.h"

/**
 * fork_example - example of fork system call
 */

void fork_example(void)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error:");
		return;
	}
	if (pid == 0)
	{
		printf("I am the child process, PID: %d", getpid());
	}
	else
	{
		printf("I am the parent process, PID: %d, Child PID: %d", getpid(), pid);
	}
}

