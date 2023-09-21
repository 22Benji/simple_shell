#include "shell.h"

/**
 * exit - exits the shell
 * @i: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int exit(i_t *i)
{
	int exitcheck;

	if (i->argv[1]) 
	{
		exitcheck = _erratoi(i->argv[1]);
		if (exitcheck == -1)
		{
			i->status = 2;
			print_error(i, "Illegal number: ");
			_eputs(i->argv[1]);
			_eputchar('\n');
			return (1);
		}
		i->err_num = _erratoi(i->argv[1]);
		return (-2);
	}
	i->err_num = -1;
	return (-2);
}

/**
 * _cd - changes the current directory of the process
 * @i: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _cd(i_t *i)
{
	char *t, *dir, buffer[1024];
	int chdir_ret;

	t = getcwd(buffer, 1024);
	if (!t)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!i->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(i->argv[1], "-") == 0)
	{
		if (!_getenv(i, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(i, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(i, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(i->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(i, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(i, "OLDPWD", _getenv(i, "PWD="));
		_setenv(i, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _help - changes the current directory of the process
 * @i: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _help(i_t *i)
{
	char **arg_array;

	arg_array = i->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}

