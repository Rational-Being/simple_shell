#include "main.h"

int main(void)
{
	int terminal = 1;
	char prompt[] = "Okoro_Yusuff_Shell# ";
	char *temp = NULL;
	ssize_t cmd = 0;
	size_t temp_size = 0;
	int clear_temp;
	pid_t child_pid;
	int status;
	char *args[2]; /* To hold both temp and NULL*/
	char *token;

	while (terminal)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, strlen(prompt));

		cmd = getline(&temp, &temp_size, stdin);

		if (cmd == -1)
		{
			/* check if ctrl+d is pressed using feof function*/
			if (feof(stdin))
				break;

			else 
			{
				perror("Okoro_Yusuff Shell:  Command Entered Doesn't Exist");
				/* print error then clear the buffer i.e. tmep */
				while ((clear_temp = getchar()) != '\n' && clear_temp != EOF);
				free(temp);
				/* Iniatialize temp and temp_size to defualt so that the program can continue to run normally*/
				temp = NULL;
				temp_size = 0;
				continue; 

			}
		}
		
		else if (temp[cmd - 1] == '\n')
				temp[cmd - 1] = '\0';

		/*tokenize the input command*/

		token = strtok(temp, " ");

		while (token != NULL)
		{
			token = strtok(NULL, " ");
		}

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("No such file or directory");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			args[0] = temp;
			args[1] = NULL;
			execve(temp, args, environ);
			perror("Failed to Execute Command");
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);



	}
	free(temp);
	return (0);
}
