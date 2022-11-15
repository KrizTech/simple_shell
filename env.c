#include <stdio.h>
#include <stdlib.h>

/**
 * check_var - checks if name match with env variable
 * @env: env variable and value
 * @name: variable name
 *
 * Return: 1 if match, 0 if not
 */
int check_var(char *env, const char *name)
{
	int i = 0;

	if (!env || !name)
		return (0);

	for (; env[i]; i++)
	{
		if (env[i] == '=')
			break;

		if (env[i] != name[i])
			return (0);
	}
	return (1);
}

/**
 * getvalue - retrieves value of env variable
 * @line: env line
 *
 * Return: parsed string
 */
char *getvalue(char *line)
{
	while (*line)
	{
		if (*line == '=')
			return (line + 1);
		line++;
	}

	return (NULL);
}

/**
 * _getenv - function  searches  the  environment list
 * @name: variable to search
 * @env: enviroment vector from main function
 *
 * Return: environment variable value
 */
char *_getenv(const char *name, char **env)
{
	char *match_line;

	while (*env)
	{
		if (check_var(*env, name))
		{
			match_line = *env;
			return (getvalue(match_line));
		}
		env++;
	}
	return (NULL);
}

/**
 * _unsetenv - function that removes variables from the environment list
 * @name: variable to be removed
 * @env: environment vector from main function
 *
 * Return: 0 if success, otherwise -1 on failure
 */

int _unsetenv(const char *name, char **env)
{
	int i, j, found_match;

	if (!name)
		return (-1);

	for (i = 0; env[i]; i++)
	{
		found_match = 1;

		for (j = 0; env[i][j] != '='; j++)
		{
			if (env[i][j] != name[j])
			{
				found_match = 0;
				break;
			}
		}

		if (found_match)
		{
			while (env[i] != NULL)
			{
				env[i] = env[i + 1];
				i++;
			}

			return (0);

		}
	}

	return (-1);
}
