#include "main.h"

/**
 * execute_if_abs_path - function to execute a command if it is an absolute path
 * @command: command passed
 * @args: arguments count
 * Return: 0 on success
 */

int execute_if_abs_path(const char *command, char *const args [])
{
	int status;
	pid_t child_pid;

	child_pid = fork();


	if (child_pid == -1)
	{
		perror("No such file or directory");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			perror("Failed to Execute Command");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	
	return (0);
}
	

/**
 * execute_search_path - funtion to execute a command y seraching path
 * @command: command passed
 * @args: argument count
 * Return: 0 on sucess
 */

int execute_search_path(const char *command, char *const args[])
{
	int status;
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *path_token = strtok(path_copy, ":");
	char command_path[1024]; /* maximum path lenght */

	pid_t child_pid = fork();

	if (path_copy == NULL)
	{
		perror("Failed to allocate memory");
		return (1);
	}

	while(path_token != NULL)
	{
		command_path[0] = '\0'; /* initialize an empty array */
		strcat(command_path, path_token);
		strcat(command_path, "/");
		strcat(command_path, command);

		if (access(command_path, X_OK) == 0)
		{
			if (child_pid == -1)
			{
				perror("No such file or directory");
				exit(EXIT_FAILURE);
			}
			else if (child_pid == 0)
			{	
				if (execve(command_path, args, environ) == -1)
				{
					perror("Failed to Execute Command");
					free(path_copy);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(&status);
				free(path_copy);
			}
			free(path_copy);
			return (0);
		}

		path_token = strtok(NULL, ":");
	}
	perror("Command not found");
	free(path_copy);

	return (1);
}

/**
 * launch_command - function to execute a commnd from user input
 * @command_line: command passed by the user
 */

int launch_command(const char *command_line)
{
	char *token;
	char *temp_command = strdup(command_line);
	int arg_count = 0;
	char *args[20];
	
	if (temp_command == NULL)
	{
		perror("failed to allocate memory");
		return (1);
	}

	token = strtok(temp_command, " ");
	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	
	args[arg_count] = NULL;

	if(arg_count > 0)
	{
		if (strchr(args[0], '/') != NULL)
			execute_if_abs_path(args[0], args);
		else
			execute_search_path(args[0], args);
	}

	free(temp_command);
	return (0);
}
