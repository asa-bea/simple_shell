#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

#define MAX_ARGS 10

/**
 * parse_arguments - Tokenizes a command string into arguments.
 * @command: The command string to parse.
 * @args: An array to store the parsed arguments.
 *
 * Return: The number of arguments parsed.
 */
int parse_arguments(char *command, char **args)
{
	char *token;
	int arg_count = 0;

	/* To Tokenize command line */
	token = strtok(command, " ");

	if (token == NULL)
	{ /* Empty Command */

		return (0);
	}

	/* Allocate memory and copy token */
	while (arg_count < MAX_ARGS)
	{
		args[arg_count] = strdup(token);
		arg_count++;

		token = strtok(NULL, " ");
		if (token == NULL)
		{
			break;
		}
	}

	/* Ensure the last element of args is NULL to terminate the arg list*/
	args[arg_count] = NULL;

	return (arg_count);
}

