#include "shell.h"
/**
 * exit_shell - exit wrapper function to exit shell
 * @command: command array to free
 * @exit_code: application exit status
 */

void exit_shell(char **command, int *exit_code)
{
	_free_dbl_ptr(command);
	exit(*exit_code);
}

/**
 * print_env - prints the enviornment variables
 * @command: command with its arguments
 * @exit_code: app exit code
 */
void print_env(char **command, int *exit_code)
{
	int i = 0;

	(void)command;
	(void)exit_code;

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
 * @exit_code: application exit status
 * Return: 0 or 1
 */

int handle_builtin(char **command, int *exit_code)
{
	builtin_t builtin[] = {{"exit", exit_shell},
												 {"env", print_env},
												 {NULL, NULL}};

	int i, flag = 0;

	for (i = 0; builtin[i].command; i++)
	{
		if (_strcmp(command[0], builtin[i].command) == 0)
		{
			(builtin[i].command_f)(command, exit_code);
			flag = 1;
			break;
		}
	}
	return (flag);
}
