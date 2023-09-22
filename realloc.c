#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@t: the pointer to the memory area
 *@c: the byte to fill *s with
 *@o: the amount of bytes to be filled
 *Return: (t) a pointer to the memory area t
 */
char *_memset(char *t, char c, unsigned int o)
{
	unsigned int j;

	for (j = 0; j < o; j++)
		s[j] = c;
	return (t);
}

/**
 * ffree - frees a string of strings
 * @qq: string of strings
 */
void ffree(char **qq)
{
	char **b = qq;

	if (!qq)
		return;
	while (*qq)
		free(*qq++);
	free(b);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *q;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	q = malloc(new_size);
	if (!q)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (q);
}

