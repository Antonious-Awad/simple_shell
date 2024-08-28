#include "shell.h"

/**
 * not_found - prints an error if command isn't found
 * @command_name: name of the command that isn't found
 * @shell_name: name of the program
 */

void not_found(char *command_name, char *shell_name)
{
	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "1", 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command_name, _strlen(command_name));
	write(STDERR_FILENO, ": not found\n", 12);
}
