#include <stdlib.h>
#include <string.h>

/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 * @dest: pointer to the destination memory area
 * @src: pointer to the source memory area
 * @n: number of bytes to copy
 * Return: pointer to dest
 */

void *_memcpy(void *dest, const void *src, size_t n)
{
	char *d = dest;
	const char *s = src;

	while (n--)
	{
		*d++ = *s++;
	}

	return (dest);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size: size of the allocated space for ptr
 * @new_size: new size for the new memory block
 * Return: pointer to the new memory block
 */

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
	{
		return (malloc(new_size));
	}

	if (new_size <= old_size)
	{
		return (ptr);
	}

	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		return (NULL);
	}

	_memcpy(new_ptr, ptr, old_size);
	free(ptr);

	return (new_ptr);
}
