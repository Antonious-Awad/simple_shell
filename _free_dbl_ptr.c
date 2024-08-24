#include "shell.h"
/**
 * _free_dbl_ptr - free a double pointer
 * @ptr: pointer to free
 */

void _free_dbl_ptr(char **ptr)
{
	int i = 0;

	if (!ptr)
		return;

	while (ptr[i] != NULL)
	{
		free(ptr[i++]);
	}
	free(ptr);
}
