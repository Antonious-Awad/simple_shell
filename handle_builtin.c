#include "shell.h"
/**
 * exit_shell - exit wrapper function to exit shell
 * @command: command array to free
 */

void exit_shell(char **command)
{
	_free_dbl_ptr(command);
	exit(EXIT_SUCCESS);
}

/**
 * handle_builtin - handles shell builtin function
 * example: exit, cd, ...etc
 * @command: command to compare with
 * Return: 0 or 1
 */

int handle_builtin(char **command)
{
	char *builtin_commands[] = {"exit", NULL};

	void (*functions[])(char **command) = {exit_shell};
	int i, flag = 0;

	for (i = 0; builtin_commands[i]; i++)
	{
		if (_strcmp(command[0], builtin_commands[i]) == 0)
		{
			(functions[i])(command);
			flag = 1;
			break;
		}
	}
	return (flag);
}
