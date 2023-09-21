#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @i: the info struct
 * @p: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(i_t *i, char *p)
{
	struct stat st;

	(void)i;
	if (!p || stat(p, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pstr, int start, int stop)
{
	static char buf[1024];
	int j = 0, l = 0;

	for (l = 0, j = start; j < stop; j++)
		if (pstr[j] != ':')
			buf[k++] = pstr[j];
	buf[l] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @i: the info struct
 * @pstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(i_t *i, char *pstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *p;

	if (!pstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pstr[i] || pstr[i] == ':')
		{
			p = dup_chars(pstr, curr_pos, i);
			if (!*p)
				_strcat(p, cmd);
			else
			{
				_strcat(p, "/");
				_strcat(p, cmd);
			}
			if (is_cmd(i, p))
				return (p);
			if (!pathstr[j])
				break;
			curr_pos = j;
		}
		i++;
	}
	return (NULL);
}

