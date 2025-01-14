#include "simple_shell.h"
#include <unistd.h>

/**
 * _getenv - get the value of an environment variable
 * @name: name of the environment variable
 * Return: value of the environment variable, or NULL if not found
 */

char *_getenv(const char *name)
{
	char **ep;
	size_t len = strlen(name);

	if (environ == NULL || name[0] == '\0')
		return (NULL);

	for (ep = environ; *ep != NULL; ++ep)
	{
		if (name[0] == (*ep)[0] && strncmp(name, *ep, len) == 0 && (*ep)[len] == '=')
		{
			return (*ep + len + 1);
		}
	}
	return (NULL);
}
