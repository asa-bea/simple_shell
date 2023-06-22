#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * void executeCommand - Simple Shell
 * Description: A simple shell implementation that reads user input,
 *              executes commands, and provides an exit built-in command.
 * Return: 0 on success.
 */

void executeCommand(char *command);

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
	printf("Shell > ");
	fgets(command, sizeof(command), stdin);

	/* Remove newline character from the command */
	command[strcspn(command, "\n")] = '\0';

	if (strcmp(command, "exit") == 0)
	{
	/* User entered 'exit', so we exit the shell */
	break;
	}

	executeCommand(command);
	}

	return 0;
	}

void executeCommand(char *command)
	{
	pid_t pid = fork();

	if (pid < 0)
	{
        /* Forking error occurred */
		perror("Fork failed");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
	/* Child process */
	execlp(command, command, NULL);

	/* If exec fails, display error message and exit child process */
	perror("Exec failed");
	exit(EXIT_FAILURE);
	}
	else
	{
	/* Parent process */
	int status;
	waitpid(pid, &status, 0);
	}
}
}
