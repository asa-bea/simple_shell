#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "shell.h"

/**
  * main - entry point
  * description - main function
  * execCommand - entry point of function
  * @ac: number of command line arguments passed to program
  * @argv: array of strings containing these arguments
  * Return: 0 on success or 1 on failure.
  */

int main(int ac, char **argv)
{
	const char prompt[] = "Liza_Asa_Shell$ ";
	size_t command_length = 0;
	ssize_t num_bytes;
	args_t arguments = {NULL, NULL};

	(void) ac;
	(void) argv;
	if (!isatty(STDIN_FILENO))
	{
		handle_non_interactive(&arguments);
		return (0);
	}
	while (1)
	{
	/* Display prompt */
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

	/* Read command line */
	num_bytes = getline(&arguments.command, &command_length, stdin);

	if (num_bytes == -1)
	{
	/* Handle end of file (Ctrl+D) */
		write(STDOUT_FILENO, "\n", 1);
		free(arguments.command);
		break;
	}

	/* Remove trailing newline character */
	arguments.command[num_bytes - 1] = '\0';

	tokenize(&arguments);

	execCommand(&arguments);
	}
	free_arguments(&arguments);
	return (0);
}

/**
  * execCommand - takes pararmeter *arguments foor command line
  * description - execute command
  * @arguments: argument passed
  */

void execCommand(args_t *arguments)
{
	const char error_msg[] = "Sorry, No such file or directory\n";
	pid_t pid;

	pid = fork(); /* Fork a child process */

	if (pid < 0)
	{
	/* Forking error, display error message and exit */
	write(STDOUT_FILENO, error_msg, sizeof(error_msg) - 1);
	free_arguments(arguments);
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{ /* Handling Child process */
	execve(arguments->token_array[0], arguments->token_array, NULL);

	write(STDOUT_FILENO, error_msg, sizeof(error_msg) - 1);
	free_arguments(arguments);
	exit(EXIT_FAILURE);
	}
	else
	{
	int status; /* Handling Parent process */

	waitpid(pid, &status, 0);
	}
}
