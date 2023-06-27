#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_non_interactive - Handle non-interactive mode
 * @arguments: The arguments structure
 *
 * This function handles the non-interactive mode
 * of the program. It reads a arguments->command
 * of input, removes the newarguments->command character,
 * tokenizes the arguments, executes the
 * command, and frees any allocated memory.
 */
void handle_non_interactive(args_t *arguments)
{
	/* Declare variables */
	size_t bufsize = 0;
	ssize_t num;

	/* Get input arguments->command */
	num = getline(&arguments->command, &bufsize, stdin);

	if (num == -1)
	{
		perror("Error");
		free(arguments->command);
		exit(1);
	}

	/* Remove newarguments->command character */
	if (arguments->command[num - 1] == '\n')
		arguments->command[num - 1] = '\0';

	/* Assign command to arguments structure */
	arguments->command = arguments->command;

	/* Tokenize arguments */
	tokenize(arguments);

	/* Execute command */
	execCommand(arguments);

	/* Free allocated memory */
	free_arguments(arguments);
}

