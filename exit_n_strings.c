#include "main.h"

/**
 * handle_exit_command - funciton that handle exit with status
 * @command_line: command passed by the user
 * Return: 0 on success, 1 on error
 */

void handle_exit_command(const char *command_line)
{
	char *token;
	char *temp_command = _strdup(command_line);
	int arg_count = 0, status;
	char *args[20];

	if (temp_command == NULL)
	{
		perror("failed to allocate memory");
		exit(1);
	}

	token = strtok(temp_command, " ");
	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}

	args[arg_count] = NULL;

	if (arg_count == 1)
	{
		free(temp_command);
		exit(0);
	}
	else if (arg_count == 2)
	{
		status = atoi(args[1]);
		free(temp_command);
		exit(status);
	}
	else
	{
		write(STDERR_FILENO, "Usage:exit [status]\n", 21);
		free(temp_command);
		exit(1);
	}
}

/**
 * _strdup - coustom strduo funtion
 * @str: string
 * Return: the new string
 */

char *_strdup(const char *str)
{
	size_t len = _strlen(str);
	size_t i = 0;
	char *new_str = (char *)malloc(len + 1);

	if (str == NULL)
		return (NULL);

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		new_str[i] = str[i];

	return (new_str);
}

/**
 * _strncmp - custom strncmp funtion
 * @s1: first string
 * @s2: second string
 * @n: number of char tobe compared
 * Return: 0 on success
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

/**
 * _strcat - custom strcat funtion
 * @dest: destination
 * @src: sorce
 * Return: the destination
 */

char *_strcat(char *dest, const char *src)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';

	return (dest);
}
