#include "main.h"


/*
 * _getenv - function to get an environment variable
 * @name: name of the command
 * Return: returns null
 */

char *_getenv(const char *cmd_name)
{
	int i = 0;
	size_t name_len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
			return environ[i] +name_len +1;
		i++;
	}
	return (NULL);
}


/*
 * gui - function to display shell prompt
 * Return: Nothing
 */

void gui()
{
	char prompt[] = "Okoro_Yusuff_Shell# ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, strlen(prompt));
}

/*
 * launch_command - command that execute command
 * @commandline: commadn passed
 * Return: 0 on sucess
 */

int launch_command(char *commandline)
{
	char *token;
	/* duplicate the command line*/
	char *temp = strdup(commandline);
	int arg_count = 0, status;
	char *args[4];
	pid_t child_pid;

	if (temp == NULL)
	{
		perror("Failed to allocate memory");
		return (1);
	}

	token = strtok(temp, " ");
	while(token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	/*null terminate the args array*/
	args[arg_count] = NULL;

	if (arg_count > 0)
	{
		if (strchr(args[0], '/') != NULL)
			{
				child_pid = fork();
		
				if (child_pid == -1)
			{
				perror("No such file or directory");
				free(temp);
				exit(EXIT_FAILURE);
			}
			else if (child_pid == 0)
			{	
				if (execve(args[0], args, environ) == -1)
				{
					perror("Failed to Execute Command");
					free(temp);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(&status);
				free(temp);
			}
			}
	}
	else
	
	return (0);
}

int main(void)
{
	int terminal = 1, clear_temp;
	char *temp = NULL;
	ssize_t cmd = 0;
	size_t temp_size = 0;

	while (terminal)
	{
		gui();

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
				/*Go back to reading input*/
				continue; 

			}
		}
		
		else if (temp[cmd - 1] == '\n')
				temp[cmd - 1] = '\0';
	
	launch_command(temp);
	
	free(temp);
	temp = NULL;
	temp_size = 0;
	}

	return (0);
}
