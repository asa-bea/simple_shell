#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_non_interactive - Handle non-interactive mode
 * @arguments: The arguments structure
 *
 * This function handles the non-interactive mode
 * of the program. It reads a line
 * of input, removes the newline character,
 * tokenizes the arguments, executes the
 * command, and frees any allocated memory.
 */
void handle_non_interactive(args_t *arguments)
{
	/* Declare variables */
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t num;

	/* Get input line */
	num = getline(&arguments->command, &bufsize, stdin);

	if (num == -1)
	{
		printf("Error reading input.\n");
		free(line);
		exit(1);
	}

	/* Remove newline character */
	if (line[num - 1] == '\n')
		line[num - 1] = '\0';

	/* Assign command to arguments structure */
	arguments->command = line;

	/* Tokenize arguments */
	tokenize(arguments);

	/* Execute command */
	execCommand(arguments);

	/* Free allocated memory */
	free_arguments(arguments);
	free(line);
}

/**
 * main: Entry point of the program
 *
 * This function demonstrates the usage of the handle_non_interactive function.
 */
int main(void)
{
	/* Example usage */
	args_t arguments;

	handle_non_interactive(&arguments);

	return (0);
}

