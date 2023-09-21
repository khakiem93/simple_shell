#include "main.h"
/**
 * main - entry point
 * @argc: arg counter
 * @argv: arg values
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	char *prompt = "$ ";
	char *input = NULL;
	size_t n = 0;
	int status = 0;
	ssize_t charsRead;
	(void)argc;
	(void)argv;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_string(prompt);
		charsRead = getline(&input, &n, stdin);
		if (charsRead == -1)
		{
			print_string("exit\n");
			return (-1);
		}
		argv = read_command_tokens(charsRead, input);
		status = _execCommand(argv);
		wait(&status);
	}
	free(input);
	free(argv);
	return (status);
}
/**
 * read_command_tokens - tokenize command token
 * @charsRead: number of char read
 * @input: input command
 * Return: argv
 */
char **read_command_tokens(ssize_t charsRead, char *input)
{
	char **argv = NULL;
	char *inputCp = NULL;
	char *tokens = NULL;
	int i, nTokens = 0;
	const char *delim = " \n";

	inputCp = malloc((sizeof(char) * charsRead) + 1);

	if (inputCp == NULL)
	{
		perror("allocation error");
	}
	_strcpy(inputCp, input);
	tokens = strtok(input, delim);

	while (tokens != NULL)
	{
		nTokens++;
		tokens = strtok(NULL, delim);
	}
	nTokens++;

	argv = malloc((sizeof(char *) * nTokens) + 1);

	tokens = strtok(inputCp, delim);

	for (i = 0; tokens != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(tokens));
		_strcpy(argv[i], tokens);
		tokens = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(tokens);
	free(inputCp);
	return (argv);
}
