#include "shell.h"
/**
 * tokenize - splits a string into an array of strings
 * @str: str to split
 * Return: array of strings
 */

char **tokenize(char *str)
{
	char **str_arr = NULL;
	char *tokenized_str = NULL;
	int i = 0;

	while (1)
	{
		/* reallocate size of array after tokenizing each part of string */
		str_arr = realloc(str_arr, sizeof(char *) * (i + 1));

		if (!str_arr)
			return (NULL);

		tokenized_str = strtok(i == 0 ? str : NULL, " ");
		if (!tokenized_str)
			break;
		str_arr[i] = tokenized_str;
		i++;
	}

	str_arr[i] = '\0';
	return (str_arr);
}
