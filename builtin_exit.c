#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * builtin_exit - Handle the built-in 'exit' command
 * @arg: The argument provided to the 'exit' command
 *
 * If @arg is NULL, exit the shell with status 0.
 * Otherwise, convert @arg to an integer and exit
 * the shell with the provided status.
 */
void builtin_exit(char *arg)
{
	int status;

	if (arg == NULL)
	{
		exit(0);  /* Exit the shell with status 0 */
	} else
	{
		if (!isnumber(arg))
		{
			write(2, "./hsh: 1: exit: Illegal number: HBTN", 37);
			exit (2);
		}

		status = atoi(arg);

		exit(status);  /* Exit shell with the provided status */
	}
}

