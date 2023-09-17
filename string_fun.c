#include "main.h"

/**
 * _strcmp - custom strcmp funtion
 * @s1: first string
 * @s2: second string
 * Return: the result
 */

int _strcmp(const char *s1, const char *s2)
{
	size_t i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;

	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/**
 * _strchar - custom strchr funtion
 * @str: the string
 * @c: no of char to compare
 * Return: nothing
 */

char *_strchar(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

/**
 * _strlen - custom strlen function
 * @Str: string passed
 * Return: len
 */

size_t _strlen(const char *Str)
{
	size_t len = 0;

	while (Str[len] != '\0')
		len++;

	return (len);
}
