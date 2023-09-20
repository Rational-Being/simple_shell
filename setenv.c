#include "main.h"

void setenv_command(const char *command_line)
{
	char *token, *value;
	char *temp_command = _strdup(command_line);

	if (temp_command == NULL)
	{
		perror("Fialed to allocate maemroy");
		return;
	}

	token = _strtok(temp_command, " ");

	if (token != NULL)
	{
		token = _strtok(NULL, " ");
		if (token != NULL)
		{
			value = strtok(NULL, " ");
			if (value != NULL)
			{
				if (setenv(token, value, 1) == -1)
					perror("setenv");
			}
			else
				perror("Error: Setenv");
		}
		else
			perror("Error: Setenv");
	}
	else
		perror("Error: Setenv");

	free(temp_command);
}


void unsetenv_command(const char *command_line)
{
	char *token;
	char *temp_command = _strdup(command_line);

	if (temp_command == NULL)
	{
		perror("Fialed to allocate maemroy");
		return;
	}

	token = _strtok(temp_command, " ");

	if (token != NULL)
	{
		token = _strtok(NULL, " ");
		if (token != NULL)
		{
			if (unsetenv(token) == -1)
					perror("unsetenv");
		}
		else
			perror("Error: Setenv");
	}
	else
		perror("Error: Setenv");

	free(temp_command);
}
