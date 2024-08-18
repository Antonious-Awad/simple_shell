#include "shell.h"
/**
 * start_loop - runs the app in interactive mode
 * @shell_name: name of the shell to print
 * @exit_code: pointer to exit code variable
 * Return: 1 if success , 0 if fails
 */

void start_loop(char *shell_name, int *exit_code)
{
	ssize_t readInputBuffer;
	size_t read_len;
	int wait_status, i;
	char *inputBuffer = NULL;
	char **command;
	pid_t pid;

	readInputBuffer = getline(&inputBuffer, &read_len, stdin);

	if (readInputBuffer == -1)
	{
		exit_code = EXIT_FAILURE;
		exit(EXIT_FAILURE);
	}

	for (i = 0; inputBuffer[i] != '\n'; i++)
		;

	inputBuffer[i] = '\0';

	command = tokenize(inputBuffer);
	if (!command)
		return;

	pid = fork();

	if (pid == -1)
	{
		*exit_code = EXIT_FAILURE;
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
			perror(shell_name);
	}
	else
		wait(&wait_status);

	free(inputBuffer);
}
