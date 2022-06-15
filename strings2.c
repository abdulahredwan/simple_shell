#include "main.h"
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: char type pointer to string
 * Return: NULL if str is NULL, or insufficient memory available
 * On success, returns a pointer to the duplicated string.
 */
char *_strdup(char *str)
{
	char *dstr;
	unsigned int size, i;

	if (str == NULL)
		return  (NULL);
	for (size = 0; str[size] != '\0'; size++)
		;
	dstr  = malloc((size + 1) * sizeof(char));

	if (dstr == NULL)
		return (NULL);
	for  (i = 0; i <  size; i++)
	{
		dstr[i] = str[i];
	}
	dstr[size] = '\0';
	return (dstr);
}
/**
 * _strlen - returns the length of a string
 * @s: char type string
 * Return: string length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * rev_string - reverses a string
 * @s: char type pointer
 */
void rev_string(char *s)
{
	int i = 0, j, l = 0;
	char k;

	while (s[i] != '\0')
	{
		i++;
	}
	i--;
	j = i;
	while (l <= j / 2)
	{
		k = s[l];
		s[l] = s[i];
		s[i] = k;
		i--;
		l++;
	}
}
/**
 * _isdigit - checks if character is a digit
 * @str: string to be checked
 * Return: 1 if it is a digit, 0 otherwise
 */
int _isdigit(const char *str)
{
	unsigned int i = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
		return (1);
}
/**
 * rpath - copies src to dest
 * @src: char type pointer
 * Return: src
 */
char *rpath(char *src)
{
	int i, j;
	char *hold;

	hold = malloc((sizeof(char) * (_strlen(src) - 9)) + 1);
	for (i = 9, j = 0; src[i] != '\0'; i++)
	{
		hold[j] = src[i];
		j++;
	}
	hold[j] = '\0';
	src = _strdup(hold);
	free(hold);
	return (src);
}
