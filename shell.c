#include "shell.h"
/**
 * main - Entry point for the shell application
 * @argc: arguments counter
 * @argv: arguments values
 * Return: exit code for the application
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	static int exit_code;
	int isInteractive = 0;

	if (isatty(STDIN_FILENO) && isatty(STDERR_FILENO))
		isInteractive = 1;

	if (isInteractive)
		start_loop(argv[0], &exit_code);
	else
	{
		char **command;

		while ((command = get_command(&exit_code)) != NULL)
		{
			if (access(command[0], X_OK | F_OK) == 0)
			{
				exec_command(command, argv[0], &exit_code);
			}
			else
			{
				fprintf(stderr, "%s: command not found\n", command[0]);
				_free_dbl_ptr(command);
				exit_code = 127;
			}
			_free_dbl_ptr(command);
		}
		_free_dbl_ptr(command);
		return (0);
	}

	return (exit_code);
}
