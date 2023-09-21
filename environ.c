#include "shell.h"

/**
 * _env - prints the current environment
 * @i: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int env(i_t *i)
{
	print_list_str(i->env);
	return (0);
}

/**
 * _genv - gets the value of an environ variable
 * @i: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_genv(i_t *i, const char *name)
{
	list_t *n = i->env;
	char qp;

	while (n)
	{
		q = starts_with(node->str, name);
		if (q && *q)
			return (q);
		n = n->next;
	}
	return (NULL);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @i: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _setenv(i_t *i)
{
	if (i->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(i, i->argv[1], i->argv[2]))
		return (0);
	return (1);
}

/**
 * _unsetenv - Remove an environment variable
 * @i: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _unsetenv(i_t *i)
{
	int x;

	if (i->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (x = 1; i <= i->argc; x++)
		_unsetenv(i, i->argv[i]);

	return (0);
}

/**
 * penv_list - populates env linked list
 * @i: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int penv_list(i_t *i)
{
	list_t *n = NULL;
	size_t x;

	for (x = 0; environ[i]; x++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

