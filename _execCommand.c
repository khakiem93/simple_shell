#include "main.h"

/**
 * _execCommand - Executes Command
 * @argv: Command arguments
 * Return: Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int _execCommand(char **argv)
{
	pid_t pid;
	int status;
	char *c = NULL;

	if (*argv == NULL)
		return (-1);
	pid = fork();

	/*char *commandPath = NULL;*/
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{

		c = argv[0];
		/*commandPath = get_path(c);*/
		if (execve(c, argv, environ) == -1)
		{
			perror("Error:");
			return (1);
		}
		else
		{
			return (0);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return (0);
		else if (WEXITSTATUS(status) == 2)
			return (2);
		else if (WEXITSTATUS(status) == 127)
			return (127);
	}
	return (127);
}

