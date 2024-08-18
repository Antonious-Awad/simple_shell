#include "shell.h"

/**
 * _put_str - print the given str
 * @str: string pointer
 * Return: length of outputted string
 */

int _put_str(char *str)
{
	int len = 0, i = 0;

	if (!str)
		return (-1);

	while (str[i] != '\0')
	{
		_putchar(str[i++]);
		len++;
	}
	return (len);
}
