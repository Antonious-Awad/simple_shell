#include "shell.h"

/**
 * count_tokens - returns the number of words separate by a space
 * @str: string to check for words
 * @delim: delimeter
 * Return: number of words
 */

int count_tokens(char *str, char delim)
{
	int i, counter = 0;

	for (i = 0; str[i] != '\0'; i++)
	{

		if (str[i] == delim || str[i + 1] == '\0')
		{
			if (str[i - 1] != delim)
				counter++;
		}
	}
	return (counter);
}

/**
 * allocate_memory - allocates memory based
 * on the size of each word in the string
 *
 * @str_arr: array of words
 * @token_count:  number of words in str
 * @delim: delimeter
 * @str: string consisting of words
 *
 */
void allocate_memory(char **str_arr, int token_count, char *str, char delim)
{
	int i, counter = 0, word_len = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (counter == token_count)
			return;

		if (str[i] != delim)
			word_len++;

		if (str[i + 1] == delim || str[i + 1] == '\0')
		{
			str_arr[counter] = malloc((word_len + 1) * sizeof(char));
			if (!str_arr[counter])
			{
				_free_dbl_ptr(str_arr);
				free(str);
				exit(EXIT_FAILURE);
			}

			word_len = 0;
			counter++;
		}
	}
}

/**
 * tokenize - splits a string into an array of strings
 * @str: str to split
 * @delim: delimeter
 * Return: array of strings
 */

char **tokenize(char *str, char delim)
{
	int tokens_counter, i, arr_itr = 0, token_itr = 0;
	char **str_arr;

	if (str == NULL || *str == '\0')
		return (NULL);

	tokens_counter = count_tokens(str, delim);

	if (!tokens_counter)
		return (NULL);

	str_arr = malloc((tokens_counter + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);

	allocate_memory(str_arr, tokens_counter, str, delim);

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] != delim)
		{
			str_arr[arr_itr][token_itr++] = str[i];
			if (str[i + 1] == delim || str[i + 1] == '\0')
			{
				str_arr[arr_itr++][token_itr] = '\0';
				token_itr = 0;
			}
		}

	str_arr[arr_itr] = NULL;
	return (str_arr);
}
