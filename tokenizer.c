#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @e: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *e)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!e)
		e = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], e) && (is_delim(str[i + 1], e) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], e))
			i++;
		k = 0;
		while (!is_delim(str[i + k], e) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @e: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int a, b, c, f, numwords = 0; //i = a   b=j k=c m=f
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[i] != '\0'; a++)
		if ((str[a] != e && str[a + 1] == e) ||
		    (str[a] != e && !str[a + 1]) || str[a + 1] == e)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (str[a] == e && str[a] != e)
			a++;
		c = 0;
		while (str[a + c] != e && str[a + c] && str[a + c] != e)
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}
		for (f = 0; f < c; f++)
			s[b][f] = str[a++];
		s[b][f] = 0;
	}
	s[b] = NULL;
	return (s);
}

