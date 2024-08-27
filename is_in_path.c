#include "shell.h"
/**
 * is_in_path - finds if the command is found in the PATH
 * environment variable
 * @command: command to find
 * @exit_code: exit_code pointer
 * @shell_name: name of the shell
 * Return: 0 if not found, 1 if found
 */

int is_in_path(char **command, int *exit_code, char *shell_name)
{
	path_t *path_list = init_path(), *head;
	int is_found = 0;
	char *full_path;

	head = path_list;
	while (path_list)
	{
		full_path = malloc((_strlen(command[0]) + 1) +
											 (_strlen(path_list->dir) + 1));
		_strcpy(full_path, path_list->dir);
		_strcat(full_path, "/");
		_strcat(full_path, command[0]);

		if (access(full_path, F_OK) == 0) /* If file exists */
		{
			if (access(full_path, X_OK) == 0) /* if file executable */
			{
				free(command[0]);
				command[0] = full_path;
				free_path(head);
				exec_command(command, shell_name, exit_code);
				is_found = 1;
				break;
			}
			else
			{
				/* handle permission denied */
				*exit_code = 126;
			}
		}
		free(full_path);
		path_list = path_list->next;
	}
	if (is_found == 0)
	{
		free_path(head);
		*exit_code = 127;
	}
	return (is_found);
}
