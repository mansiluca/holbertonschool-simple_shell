#include <stddef.h>
#include "simple_shell.h"

/**
 * _strtok - tokenizes a string
 * @str: string to tokenize
 * @delim: delimiter
 * Return: pointer to token
 */

char *_strtok(char *str, const char *delim)
{
	static char *last;
	char *token = str;

	if (str == NULL)
	{
		str = last;
	}
	if (str == NULL)
	{
		return (NULL);
	}

	while (*str && strchr(delim, *str))
		str++;

	if (*str == '\0')
	{
		last = NULL;
		return (NULL);
	}

	while (*str && !strchr(delim, *str))
		str++;

	if (*str)
	{
		*str = '\0';
		last = str + 1;
	} else
	last = NULL;

	return (token);
}
