#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * read_line - Read a line from standard input
 *
 * Description: Reads characters from standard input into a buffer until
 *              a newline character is encountered.
 *
 * Return: The line read from input, or NULL on failure or EOF.
 */
char *read_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_index;
	static int chars_read;

	char *line = NULL;
	int line_index = 0;
	int c;

	while (1)
	{
		/* If buffer_index is 0 or chars_read is 0, refill the buffer */
		if (buffer_index == 0 || buffer_index == chars_read)
		{
			buffer_index = 0;
			chars_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (chars_read == 0)
				break;
		}

		c = buffer[buffer_index++];
		if (c == '\n' || c == EOF)
		{
			line[line_index++] = '\0';
			break;
		}

		line = realloc(line, (line_index + 1) * sizeof(char));
		line[line_index++] = c;
	}

	if (line == NULL && line_index == 0)
		return (NULL);

	return (line);
}

/**
 * split_line - Split a line into individual tokens
 * @line: The input line to be split
 * @delimiters: The characters used as delimiters to split the line
 *
 * Description: Splits the input line into individual tokens
 *              characters. Returns an array of strings, each element as token.
 *
 * Return: An array of strings, where each element is a token.
 */
char **split_line(char *line, char *delimiters)
{
	char **tokens = NULL;
	char *token;
	int token_count = 0;

	token = strtok(line, delimiters);
	while (token != NULL)
	{
		token_count++;
		tokens = realloc(tokens, token_count * sizeof(char *));
		tokens[token_count - 1] = token;

		token = strtok(NULL, delimiters);
	}

	token_count++;
	tokens = realloc(tokens, token_count * sizeof(char *));
	tokens[token_count - 1] = NULL;

	return (tokens);
}

/**
 * execute - Execute a command with arguments
 * @args: The array of arguments
 *
 * Description: Executes a command with the arg using the execvp system call.
 *              Command should be located in one of the directories in the PATH
 *              environment variable.
 */
void execute(char **args)
{
	if (execvp(args[0], args) == -1)
	{
		perror("execvp");
		exit(EXIT_FAILURE);
	}
}

