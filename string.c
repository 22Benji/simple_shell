#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @t: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *t)
{
	int j = 0;

	if (!t)
		return (0);

	while (*t++)
		j++;
	return (j);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @st1: the first strang
 * @st2: the second strang
 *
 * Return: negative if st1 < st2, positive if st1 > st2, zero if st1 == st2
 */
int _strcmp(char *st1, char *st2)
{
	while (*st1 && *st2)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
	}
	if (*st1 == *st2)
		return (0);
	else
		return (*st1 < *st2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @des: the destination buffer
 * @sr: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *des, char *sr)
{
	char *ret = des;

	while (*des)
		des++;
	while (*sr)
		*des++ = *sr++;
	*des = *sr;
	return (ret);
}

