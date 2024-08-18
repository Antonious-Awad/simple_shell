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
		while (1)
		{
			_put_str("($) ");

			start_loop(argv[0], &exit_code);
		}
	else
	{
		start_loop(argv[0], &exit_code);
	}

	return (exit_code);
}
