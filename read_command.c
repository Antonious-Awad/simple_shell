#include "shell.h"

/**
 * add_null - add null character to end of string read by getline
 * @inputBuffer: input string
 */
void add_null(char *inputBuffer)
{
	int i;

	for (i = 0; inputBuffer[i] != '\n'; i++)
		;
	inputBuffer[i] = '\0';
}

/**
 * get_command - reads  string from stdin
 * and creates an array of the command with its
 * @exit_code: exit code pointer
 *
 * Return: array of strings of the command with its arguments
 */

char **get_command(int *exit_code)
{
	char **command = NULL, *inputBuffer = NULL;
	ssize_t readInputSize;
	size_t read_len = 0;

	readInputSize = getline(&inputBuffer, &read_len, stdin);
	if (readInputSize == -1)
	{
		free(inputBuffer);
		*exit_code = EXIT_SUCCESS;
		return (NULL);
	}

	if (inputBuffer[0] == '\n')
	{
		free(inputBuffer);
		return (NULL);
	}

	add_null(inputBuffer);
	command = tokenize(inputBuffer, ' ');

	if (command == NULL || command[0] == NULL)
	{
		free(inputBuffer);
		return (NULL);
	}

	free(inputBuffer);
	return (command);
}

/**
 * exec_command - executes a command by forking a new process
 * @command: command
 * @shell_name: name of shell
 * @exit_code: pointer to exit code
 */
void exec_command(char **command, char *shell_name, int *exit_code)
{
	pid_t pid;
	int wait_status;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork");
		_free_dbl_ptr(command);
		*exit_code = EXIT_FAILURE;
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(shell_name);
			_free_dbl_ptr(command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&wait_status);
		*exit_code = WEXITSTATUS(wait_status);
	}
}

/**
 * start_loop - runs the app in interactive mode
 * @shell_name: name of the shell to print
 * @exit_code: pointer to exit code variable
 */

void start_loop(char *shell_name, int *exit_code)
{
	char **command;
	int isBuiltin, isInPath;

	while (1)
	{
		_put_str("($) ");
		command = get_command(exit_code);
		if (command == NULL || command[0] == NULL)
		{
			_free_dbl_ptr(command);
			continue;
		}
		isBuiltin = handle_builtin(command, exit_code);
		if (isBuiltin == 1)
		{
			_free_dbl_ptr(command);
			continue;
		}
		isInPath = is_in_path(command, exit_code, shell_name);
		if (isInPath)
		{
			_free_dbl_ptr(command);
			continue;
		}
		if (access(command[0], X_OK | F_OK) == 0)
		{
			exec_command(command, shell_name, exit_code);
			continue;
		}
		else
		{
			not_found(command[0]);
			_free_dbl_ptr(command);
			continue;
		}
	}
}
