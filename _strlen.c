/**
 * _strlen - returns string length
 * @s: string pointer
 * Return: Count
 */

int _strlen(char *s)
{
	int count;

	if (*s == '\0')
		return (0);
	count = _strlen(s + 1) + 1;
	return (count);
}
