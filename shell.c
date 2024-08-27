#include "shell.h"

/**
 * non_interactive - handling non-interactive mode
 * @shell_name: name of the shell to print
 * @exit_code: pointer to exit code variable
 */

void non_interactive(char *shell_name, int *exit_code)
{
	char **command;
	int isBuiltin, isInPath;

	while ((command = get_command(exit_code)) != NULL)
	{
		if (command == NULL || command[0] == NULL)
		{
			_free_dbl_ptr(command);
			exit(EXIT_SUCCESS);
		}
		isBuiltin = handle_builtin(command, exit_code);
		if (isBuiltin == 1)
		{
			_free_dbl_ptr(command);
			exit(EXIT_SUCCESS);
		}
		isInPath = is_in_path(command, exit_code, shell_name);
		if (isInPath)
		{
			_free_dbl_ptr(command);
			exit(EXIT_SUCCESS);
		}
		if (access(command[0], X_OK | F_OK) == 0)
		{
			exec_command(command, shell_name, exit_code);
			_free_dbl_ptr(command);
		}
		else
		{
			*exit_code = 127;
			not_found(command[0], shell_name);
			_free_dbl_ptr(command);
		}
	}
}
/**
 * main - Entry point for the shell application
 * @argc: arguments counter
 * @argv: arguments values
 * Return: exit code for the application
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	int exit_code;
	int isInteractive = 0;

	if (isatty(STDIN_FILENO) && isatty(STDERR_FILENO))
		isInteractive = 1;

	if (isInteractive)
		start_loop(argv[0], &exit_code);
	else
		non_interactive(argv[0], &exit_code);

	return (exit_code);
}
