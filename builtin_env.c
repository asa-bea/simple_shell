#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * executeCommand - Executes a command.
 * @command: The command to be executed.
 *
 * Description: This function executes the specified command.
 */
void executeCommand(char *command)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		/* Forking error occurred */
		write(STDERR_FILENO, "Fork failed\n", 12);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		char *args[2];

		args[0] = command;
		args[0] = command;

		args[1] = NULL;

		execvp(args[0], args);

		/* If exec fails, display error message and exit child process */
		write(STDERR_FILENO, "Exec failed\n", 12);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		int status;

		waitpid(pid, &status, 0);
	}
}

