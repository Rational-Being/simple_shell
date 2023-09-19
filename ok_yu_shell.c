#include "main.h"

/**
 * gui - function to display shell prompt
 * Return: Nothing
 */

void gui(void)
{
	char prompt[] = "Yusuff_Okoro_Shell# ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, _strlen(prompt));
}

/**
 * main - the main funtion for th simple shell
 * Return: 0 on success
 */

int main(void)
{
	int terminal = 1;
	char *temp = NULL;
	ssize_t cmd = 0;
	size_t temp_size = 0;

	while (terminal)
	{
		gui();

		cmd = getline(&temp, &temp_size, stdin);

		if (cmd == EOF)
		{
			free(temp);
			break;
		}
		else if (cmd == -1)
		{
			perror("Input Probably wrong");
		}
		else
		{
			if (temp[cmd - 1] == '\n')
				temp[cmd - 1] = '\0';

			launch_command(temp);
	}

	free(temp);
	temp = NULL;
	temp_size = 0;

	}

	return (0);
}
