#include "shell.h"

/**
 * free_string_and_tokens - Free the memory for the string and token array
 * @str: The string to free
 * @tokens: The array of tokens to free
 */
void free_string_and_tokens(char *str, char **tokens)
{
	if (str)
		free(str);
	if (tokens)
		_free_dbl_ptr(tokens);
}
