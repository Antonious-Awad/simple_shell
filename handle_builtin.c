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
 * print_env - prints the enviornment variables
 * @command: command with its arguments
 */
void print_env(char **command)
{
	int i = 0;

	(void)command;

	while (environ[i])
	{
		_put_str(environ[i++]);
		_putchar('\n');
	}
}

/**
 * handle_builtin - handles shell builtin function
 * example: exit, cd, ...etc
 * @command: command to compare with
 * Return: 0 or 1
 */

int handle_builtin(char **command)
{
	builtin_t builtin[] = {{"exit", exit_shell},
												 {"env", print_env},
												 {NULL, NULL}};

	int i, flag = 0;

	for (i = 0; builtin[i].command; i++)
	{
		if (_strcmp(command[0], builtin[i].command) == 0)
		{
			(builtin[i].command_f)(command);
			flag = 1;
			break;
		}
	}
	return (flag);
}
