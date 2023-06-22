#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * executeCommand - entry point
 * @char  - charcter
 * Description: A simple shell implementation that executes the 'env' command
 *              to print the current environment.
 * Return: 0 on success.
 */

	void executeCommand(char *command);

	int main(void)
	{
	char command[] = "env";

	executeCommand(command);

	return (0);
	}

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
	char *args[] = {command, NULL};

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

