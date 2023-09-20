#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int c = fgetc(stream);
	size_t i = 0;
	char *temp;

	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while (1)
	{
		if (c == EOF)
		{
		if (i == 0)
		{
			free(*lineptr);
			*lineptr = NULL;
		}
		return (ssize_t)i;
		}
	if (i >= *n - 1)
	{
		*n *= 2;
		temp = (char *)malloc(*n * 2);
		if (temp == NULL)
			return (-1);
		memcpy(temp, *lineptr, i);
		free(*lineptr);
		*lineptr = temp;
	}

	(*lineptr)[i++] = (char)c;

	if (c == '\n')
		break;
	}
	(*lineptr)[i] = '\0';
	return (ssize_t)i;
}


