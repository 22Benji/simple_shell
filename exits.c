#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int o)
{
	int j, k;
	char *s = dest;

	j = 0;
	while (src[j] != '\0' && j < o - 1)
	{
		dest[j] = src[j];
		j++;
	}
	if (i < o)
	{
		k = j;
		while (k < o)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int o)
{
	int j, k;
	char *s = dest;

	j = 0;
	k = 0;
	while (dest[j] != '\0')
		j++;
	while (src[k] != '\0' && k < o)
	{
		dest[j] = src[k];
		j++;
		k++;
	}
	if (k < o)
		dest[j] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char d)
{
	do {
		if (*s == d)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

