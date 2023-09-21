#include "shell.h"

/**
 * history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @i: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int history(i_t *i)
{
	print_list(i->history);
	return (0);
}

/**
 * ualias - sets alias to string
 * @i: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int ualias(i_t *i, char *str)
{
	char *q, d;
	int ret;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	d = *q;
	*q = 0;
	ret = delete_node_at_index(&(i->alias),
		get_node_index(i->alias, node_starts_with(i->alias, str, -1)));
	*q = d;
	return (ret);
}

/**
 * salias - sets alias to string
 * @i: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int salias(i_t *i, char *str)
{
	char *q;

 q = _strchr(str, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (ualias(i, str));

	ualias(i, str);
	return (add_node_end(&(i->alias), str, 0) == NULL);
}

/**
 * palias - prints an alias string
 * @n: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int palias(list_t *n)
{
	char *q = NULL, *b = NULL;

	if (n)
	{
		q = _strchr(n->str, '=');
		for (b = node->str; b <= q; b++)
		_putchar(*b);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _malias - mimics the alias builtin (man alias)
 * @i: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _malias(i_t *i)
{
	int i = 0;
	char *q = NULL;
	list_t *n = NULL;

	if (i->argc == 1)
	{
		n = i->alias;
		while (n)
		{
			palias(n);
			n = n->next;
		}
		return (0);
	}
	for (i = 1; i->argv[i]; i++)
	{
		q = _strchr(i->argv[i], '=');
		if (q)
			salias(i, i->argv[i]);
		else
			palias(n_starts_with(i->alias, i->argv[i], '='));
	}

	return (0);
}

