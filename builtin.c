#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * shell - Simple shell implementation
 *
 */
void _exit(args_t *argument)
{
	int code = 0;

	if (argument->token_array[1] != NULL)
		code = _atoi(argument->token_array[1]);
	exit(code);
}
