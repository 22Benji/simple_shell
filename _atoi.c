#include "shell.h"

/**
 * inter - returns true if shell is interactive mode
 * @x: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int inter(x_t *x)
{
	return (isatty(STDIN_FILENO) && x->readfd <= 2);
}

/**
 * is_de - checks if character is a delimeter
 * @x: the char to check
 * @de: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_de(char x, char *de)
{
	while (*de)
		if (*de++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @x: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @y: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *y)
{
	int i, s = 1, f = 0, output;
	unsigned int result = 0;

	for (i = 0; y[i] != '\0' && f != 2; i++)
	{
		if (y[i] == '-')
			s*= -1;

		if (y[i] >= '0' && y[i] <= '9')
		{
			f = 1;
			result *= 10;
			result += (y[i] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (s == -1)
		output = -result;
	else
		output = result;

	return (output);
}
