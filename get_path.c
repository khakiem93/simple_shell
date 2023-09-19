#include "main.h"
/**
 * get_path - get command path
 * @command: Command
 * Return: command path
 */
char *get_path(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, dir_len;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		path_copy = malloc(sizeof(char) * _strlen(path));
		_strcpy(path_copy, path);
		command_length = _strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			dir_len = _strlen(path_token);
			file_path = malloc(command_length + dir_len + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
/**
 * _getenv - Gets the value of environment variable by name
 * @name: Environment variable name
 * Return: The value of the environment variable or NULL if failed
 */
char *_getenv(char *name)
{
	size_t name_len, value_len;
	char *value;
	int i, j, k;

	name_len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strcmp(name, environ[i]) == 1)
		{
			value_len = _strlen(environ[i]) - name_len;
			value = malloc(sizeof(char) * value_len);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (k = name_len + 1; environ[i][k]; k++, j++)
			{
				value[j] = environ[i][k];
			}
			value[j] = '\0';

			return (value);
		}
	}
	return (NULL);
}
