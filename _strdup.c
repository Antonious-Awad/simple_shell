#include "shell.h"
/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer
 */

char *_strdup(const char *str)
{
	char *dup;
	int len, i;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str);
	dup = malloc(len * sizeof(*dup) + 1);
	if (dup == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		dup[i] = str[i];
	}
	dup[i] = '\0';
	return (dup);
}
