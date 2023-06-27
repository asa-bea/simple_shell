#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * shell - Simple shell implementation
 *
 */
void shell(void)
{
	char command[MAX_COMMAND_LENGTH];
	ssize_t numBytes;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		numBytes = read(STDIN_FILENO, command, sizeof(command));
		if (numBytes == -1)
		{
			exit(1);
		}

		command[numBytes - 1] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			exit(0);
		} else
		{
			system(command);
		}
	}
}

