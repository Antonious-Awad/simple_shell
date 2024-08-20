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

		command = get_command(&exit_code);
		if (access(command[0], X_OK | F_OK) == -1)
		{
			perror("access err");
			exit_code = EXIT_FAILURE;
			exit(EXIT_FAILURE);
		}

		exec_command(command, argv[0], &exit_code);
	}

	return (exit_code);
}
