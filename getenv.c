#include "main.h"

/*
 * _getenv - coustom getenv function
 * @cmd_name - thename of the command
 * Return: NULL
 */

char *_getenv(const char *cmd_name)
{
	int i = 0;
	size_t name_len = strlen(cmd_name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], cmd_name, name_len) == 0 && environ[i][name_len] == '=')
		{
			return (environ[i] + name_len + 1);
		}
		i++;
	}
	return (NULL);
}

/**
 * launch_env - fucntion responsible for the executing the env command
 * the funstion will print the current environment varables
 * Return: 0 on success
 */

int launch_env(void)
{
	char **env = environ;
	char *env_var = *env;
	size_t env_var_len = 0;

	while (*env)
	{
		while(env_var[env_var_len] != '\0')
			env_var_len++;

		write(STDOUT_FILENO, env_var, env_var_len);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
	return 0;
}
