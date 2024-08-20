#include "shell.h"

/**
 * count_words - returns the number of words separate by a space
 * @str: string to check for words
 * Return: number of words
 */

int count_words(char *str)
{
	int i, counter = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' || str[i + 1] == '\0')
		{
			if (str[i - 1] != ' ')
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
 * @word_counter:  number of words in str
 * @str: string consisting of words
 *
 */
void allocate_memory(char **str_arr, int word_counter, char *str)
{
	int i, counter = 0, word_len = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (counter == word_counter)
			return;

		if (str[i] != ' ')
			word_len++;

		if (str[i + 1] == ' ' || str[i + 1] == '\0')
		{
			str_arr[counter++] = malloc((word_len + 1) * sizeof(char));
			word_len = 0;
		}
	}
}

/**
 * tokenize - splits a string into an array of strings
 * @str: str to split
 * Return: array of strings
 */

char **tokenize(char *str)
{
	int word_counter, i, arr_itr = 0, word_itr = 0;
	char **str_arr;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_counter = count_words(str);

	if (!word_counter)
		return (NULL);

	str_arr = malloc((word_counter + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	allocate_memory(str_arr, word_counter, str);

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] != ' ')
		{
			str_arr[arr_itr][word_itr++] = str[i];
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
			{
				str_arr[arr_itr++][word_itr] = '\0';
				word_itr = 0;
			}
		}

	str_arr[arr_itr] = NULL;
	return (str_arr);
}
