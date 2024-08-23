#include "shell.h"

/**
 * _strncmp - compares 2 strings up to n characters
 * @s1: 1st string
 * @s2: 2nd string
 * @n: characters to compare
 * Return: difference between ascii characters of the 2 strings
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	if (n == 0)
		return (0);

	while (n--)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		else if (*s1 == '\0' || *s2 == '\0')
			return (0);

		s1++;
		s2++;
	}
	return (0);
}
