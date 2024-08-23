#include "shell.h"

/**
 * free_path - frees the path list
 * @head: head node
 */

void free_path(path_t *head)
{
	path_t *temp;

	temp = head;
	while (!temp)
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

	new_node->dir = strdup(str);

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

	__attribute__((unused)) char *path_val = _getenv("PATH");
	path_t *head = NULL;

	return (head);
}
