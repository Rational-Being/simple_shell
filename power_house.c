#include "main.h"

/**
 * execute_if_abs_path - function to execute command if it is an absolute path
 * @command: command passed
 * @args: arguments count
 * Return: 0 on success
 */

int execute_if_abs_path(const char *command, char *const args[])
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
 * search_command_in_path - funtion to execute a command y seraching path
 * @command: command passed
 * @command_path: command's path
 * Return: 0 on sucess, 1 on error
 */

int search_command_in_path(const char *command, char *command_path)
{
	char *path = _getenv("PATH");
	char *path_copy = _strdup(path);
	char *path_token = _strtok(path_copy, ":");

	if (path_copy == NULL)
	{
		perror("Failed to allocate memory");
		return (1);
	}
	while (path_token != NULL)
	{
		command_path[0] = '\0'; /* initialize an empty array */
		_strcat(command_path, path_token);
		_strcat(command_path, "/");
		_strcat(command_path, command);

		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (0); /* command found in path */
		}

		path_token = _strtok(NULL, ":");
	}

	free(path_copy);
	return (1);
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
	char command_path[1024]; /* maximum path lenght */
	pid_t child_pid = fork();

	if (search_command_in_path(command, command_path) == 0)
	{
		if (child_pid == -1)
		{
			print_error(args[0], "No such file or directory", __LINE__);
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			if (execve(command_path, args, environ) == -1)
			{
				print_error(args[0], "Failed to execute command", __LINE__);
				exit(EXIT_FAILURE);
			}
			else
				execve(command_path, args, environ);
		}
		else
		{
			wait(&status);
		}

		return (0);
	}
	else
	{
		print_error(args[0], "Command not found", __LINE__);
		return (1);
	}
}

/**
 * launch_command - function to execute a commnd from user input
 * @command_line: command passed by the user
 * Return: 0 on success, 1 on error
 */

int launch_command(const char *command_line)
{
	char *token;
	char *temp_command = _strdup(command_line);
	int arg_count = 0;
	char *args[20];

	if (temp_command == NULL)
	{
		perror("failed to allocate memory");
		return (1);
	}

	token = _strtok(temp_command, " ");
	while (token != NULL)
	{
		args[arg_count++] = token;
		token = _strtok(NULL, " ");
	}

	args[arg_count] = NULL;

	if (arg_count > 0)
	{
		if (_strcmp(args[0], "exit") == 0)
			handle_exit_command(command_line);
		else if (_strcmp(args[0], "env") == 0)
			launch_env();
		else if (_strchr(args[0], '/') != NULL)
			execute_if_abs_path(args[0], args);
		else
			if (execute_search_path(args[0], args) != 0)
			{
				print_error(args[0], "Command not found", __LINE__);
				free(temp_command);
				return (1);
/*				exit(EXIT_FAILURE);*/
			}
	}

	free(temp_command);
	return (0);
}
