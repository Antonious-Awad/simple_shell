#include "shell.h"
/**
 * _getenv - returns the environment variable
 * from environment array
 * @env_var: environment variable
 * Return: value of the environment variable
 */

char *_getenv(char *env_var)
{
	int i;
	int var_len = _strlen(env_var);

	for (i = 0; environ[i]; i++)
	{

		if (_strncmp(env_var, environ[i], var_len) == 0 &&
				environ[i][var_len] == '=')
		{
			return (&environ[i][var_len] + 1);
		}
	}
	return (NULL);
}
