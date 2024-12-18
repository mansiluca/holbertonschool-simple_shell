#include "simple_shell.h"

/**
 * print_ppid - prints the parent process id
 */

void print_ppid(void)
{
	printf("PPID: %d", getppid());
}
