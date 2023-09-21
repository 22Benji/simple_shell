#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @i: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(i_t *i)
{
	if (!i->environ || i->env_changed)
	{
		i->environ = list_to_strings(i->env);
		i->env_changed = 0;
	}

	return (i->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(i_t *i, char *var)
{
	list_t *n = i->env;
	size_t j = 0;
	char *q;

	if (!n || !var)
		return (0);

	while (n)
	{
		q = starts_with(node->str, var);
		if (q && *q == '=')
		{
			i->env_changed = delete_node_at_index(&(i->env), i);
			j = 0;
			n = i->env;
			continue;
		}
		n = n->next;
		j++;
	}
	return (i->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *n;
	char *q;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	n = i->env;
	while (n)
	{
		q = starts_with(n->str, var);
		if (q && *q == '=')
		{
			free(n->str);
			n->str = buf;
			i->env_changed = 1;
			return (0);
		}
		n = n->next;
	}
	add_node_end(&(i->env), buf, 0);
	free(buf);
	i->env_changed = 1;
	return (0);
}

