#include "simple_shell.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to be scanned
 * @accept: the string containing the characters to match
 *
 * Return: the number of characters in the initial segment of s
 * which consist only of characters from accept
 */
size_t _strspn(const char *s, const char *accept)
{
	const char *p;
	const char *a;
	size_t count = 0;

	for (p = s; *p != '\0'; ++p)
	{
		for (a = accept; *a != '\0'; ++a)
		{
			if (*p == *a)
			{
				break;
			}
		}
		if (*a == '\0')
		{
			return (count);
		}
		++count;
	}
	return (count);
}

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to be scanned
 * @accept: the string containing the characters to match
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found
 */
char *_strpbrk(const char *s, const char *accept)
{
	const char *p;
	const char *a;

	for (p = s; *p != '\0'; ++p)
	{
		for (a = accept; *a != '\0'; ++a)
		{
			if (*p == *a)
			{
				return ((char *)p);
			}
		}
	}
	return (NULL);
}

/**
 * _strtok_r - tokenizes a string, reentrant version
 * @str: the string to be tokenized
 * @delim: the delimiter string
 * @saveptr: pointer to a char* variable that is used internally
 *
 * Return: a pointer to the next token, or NULL if there are no more tokens
 */
char *_strtok_r(char *str, const char *delim, char **saveptr)
{
	char *token;

	if (str == NULL)
	{
		str = *saveptr;
	}
	str += _strspn(str, delim);
	if (*str == '\0')
	{
		*saveptr = str;
		return (NULL);
	}

	token = str;
	str = _strpbrk(token, delim);
	if (str == NULL)
	{
		*saveptr = strchr(token, '\0');
	} else
	{
		*str = '\0';
		*saveptr = str + 1;
	}

	return (token);
}
