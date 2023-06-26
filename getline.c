#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * my_getline - Custom getline function
 *
 * Description: Reads characters from standard input into a buffer
 *              using a static variable and minimizes the number of
 *              read system calls.
 *
 * Return: Line read from input, or NULL on failure or EOF.
 */
char *my_getline(void)
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
			chars_read = fread(buffer, sizeof(char), BUFFER_SIZE, stdin);
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
 * main - Entry point
 *
 * Description: Reads a line from the user and prints it.
 *
 * Return: Always 0
 */
int main(void)
{
	char *prompt = "Enter a line: ";
	char *line;

	line = my_getline();

	write(STDOUT_FILENO, prompt, strlen(prompt));

	if (line != NULL)
	{
		char *output = "You entered: ";

		write(STDOUT_FILENO, output, strlen(output));
		write(STDOUT_FILENO, line, strlen(line));
		write(STDOUT_FILENO, "\n", 1);
		free(line);
	}

	else
	{
		char *error = "Error reading input.\n";

		write(STDOUT_FILENO, error, strlen(error));
	}

	return (0);
}

