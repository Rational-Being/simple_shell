#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t line_length = get_next_line(lineptr, n);

	if (lineptr == NULL || n == NULL)
	{
		errno = EINVAL;
		return (-1);
	}

	if (line_length < 0)
		return (line_length);

	return (line_length);
}

ssize_t read_into_buffer(FILE *stream)
{
	static char input_buffer[BUFFER_SIZE];
	static size_t buffer_pos = 0;
	static ssize_t buffer_size = 0;
	buffer_size = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
	buffer_pos = 0;
	return (buffer_size);
}

ssize_t get_next_line(char **lineptr, size_t *n)
{
	ssize_t read_bytes, line_length = 0, required_size = line_length + 1;
	char *newline = NULL;

	if (buffer_size == 0)
		read_bytes = read_into_buffer(stdin);
	if (read_bytes <= 0)
		return (read_bytes);

	while(buffer_pos + line_length < buffer_size)
	{
		if (input_buffer[buffer_pos + line_length] == '\n')
		{
			newline = &input_buffer[buffer_pos + line_length];
			line_length++;
			break;
		}
		line_length++;
	}
	if (*n < required_size)
	{
		if (new_lineptr == NULL)
		{
			errno = ENOMEM;
			return -1;
		}
		*lineptr = new_lenght;
		*n = requred_size;
	}

	if (line_length > 0)
		memcpy(*line)

	(*lineptr)[line_length] = '\0';

	buffer_pos += line_length;

	if (newline != NULL)
		buffer_pos++;

	if (buffer_pos >= buffer_size)
	{
		if (read_bytes <= 0)
			return read_bytes;
	}
	return line_length;
}



























