#include "shell.h"

/**
 * not_found - prints an error if command isn't found
 * @command_name: name of the command that isn't found
 */

void not_found(char *command_name)
{
	char **err_buffer;
	int i = 0;

	err_buffer = malloc(sizeof(char *) * 4);

	err_buffer[0] = command_name;
	err_buffer[1] = ":";
	err_buffer[2] = "command not found\n";
	err_buffer[3] = NULL;

	while (err_buffer[i])
	{
		write(STDERR_FILENO, err_buffer[i], _strlen(err_buffer[i]));
		i++;
	}
	free(err_buffer);
}
