#include "shell.h"
/**
 * _strcat - concatenates strings
 * @dest: destination
 * @src: input
 * Return: concatenated string
 */
char *_strcat(char *dest, const char *src)
{

	int destLen = _strlen(dest), i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[destLen++] = src[i];
	}
	dest[destLen] = '\0';
	return (dest);
}
