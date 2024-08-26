#include "shell.h"

/**
 * count_dir - counts the number of directories in path
 * @path_val: value of path env var
 * Return: number of directories in path
 */
int count_dir(const char *path_val)
{
	int i, count = 1;

	for (i = 0; path_val[i]; i++)
		if (path_val[i] == ':')
			count++;

	return (count);
}

/**
 * free_path - frees the path list
 * @head: head node
 */

void free_path(path_t *head)
{
	path_t *temp;

	temp = head;
	while (temp)
	{
		temp = temp->next;
		free(head->dir);
		free(head);
		head = temp;
	}
}

/**
 * add_node_end - adds a node to the end
 * @head: head pointer
 * @str: new node str
 * Return: list node
 */

path_t *add_node_end(path_t **head, const char *str)
{
	path_t *new_node, *current;

	new_node = malloc(sizeof(path_t));

	if (!new_node)
		return (NULL);

	new_node->dir = _strdup(str);
	new_node->next = NULL;

	if (!new_node->dir)
	{
		free(new_node->dir);
		free(new_node);
		return (NULL);
	}

	current = *head;

	if (!current)
		*head = new_node;
	else
	{
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_node;
	}
	return (*head);
}

/**
 * init_path - initialize the path single linked list
 * Return: Head pointer of the single linked list
 */

path_t *init_path(void)
{
	int dir_count, i;
	char *path_val = _getenv("PATH"), **path_arr;
	path_t *head = NULL;

	if (!path_val || path_val[0] == '\0')
		return (NULL);

	dir_count = count_dir(path_val);
	path_arr = tokenize(path_val, ':');

	for (i = 0; i < dir_count; i++)
	{
		head = add_node_end(&head, path_arr[i]);
	}

	_free_dbl_ptr(path_arr);
	return (head);
}
