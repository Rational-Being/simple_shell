#include "main.h"

/* _getenv - coustom getenv function
 * @cmd_name - thename of the command
 * Return: NULL
 */

char *_getenv(const char *cmd_name)
{
	int i = 0;
	size_t name_len = strlen(cmd_name);

	while (environ[i] != NULL)
	{
		if (strcmp(environ[i], cmd_name, name_len) == 0 && environ[i][name_len] == '=')
			return environ[i] +name_len +1;
		i++;
	}
	return (NULL);
}
