#include "main.h"

/**
 * _execCommand - Executes Command
 * @argv: Command arguments
 * Return: void
 */
void _execCommand(char **argv)
{
	char *c = NULL;
	char *commandPath = NULL;

	if (argv)
	{
		c = argv[0];
		commandPath = get_path(c);
		if (execve(commandPath, argv, environ) == -1)
		{
			perror("Error:");
		}
	}
}
