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
	char *input;
	size_t n = 0;
	ssize_t charsRead;
	(void)argc;
	(void)argv;
	while (1)
	{
		print_string(prompt);
		charsRead = getline(&input, &n, stdin);
		if (charsRead == -1)
		{
			print_string("exit\n");
			return (-1);
		}
		argv = read_command_tokens(charsRead, input);
		_execCommand(argv);
		print_string(input);
		print_string("\n");
	}
	free(input);
	free(argv);
	return (0);
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
	char *inputCp;
	char *tokens;
	int i, nTokens = 0;
	const char *delim = " \n";

	inputCp = malloc(sizeof(char) * charsRead);
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

	argv = malloc(sizeof(char *) * nTokens);

	tokens = strtok(inputCp, delim);

	for (i = 0; tokens != NULL; i++)
	{
		
		argv[i] = malloc(sizeof(char) * _strlen(tokens));
		_strcpy(argv[i], tokens);
		tokens = strtok(NULL, delim);
	}
	argv[i] = NULL;

	free(inputCp);
	return (argv);
}
