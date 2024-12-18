#include "simple_shell.h"

/**
 * wait_example - example of wait system call
 */

void wait_example(void)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("Error:");
		return;
	}
	if (pid == 0)
	{
		printf("Child process working...");
		sleep(3);
		printf("Child process done");
	}
	else
	{
		wait(&status);
		printf("Parent process: child exited");
	}
}

