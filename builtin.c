#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * _exit_status - Terminate the shell process.
 * @argument: Pointer to the argument structure.
 *
 * This function is called when the "exit" command is executed in the shell.
 * It terminates the shell process with the specified exit code, or 0 if no
 * exit code is provided.
 */
void _exit_status(args_t *argument)
{
	int code = 0;

	if (argument->token_array[1] != NULL)
		code = _atoi(argument->token_array[1]);
	exit(code);
}
