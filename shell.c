#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

/**
  * main - entry point of function
  * @char* command = NULL - Stores the command entered by the user
  * @size_t command_length - Stores the length of the command
  * @ssize_t num_bytes - Stores the number of bytes read by getline
  * @char* token - Stores the tokenized command
  * @char* args[2] - Stores the arguments for execve
  * @const char prompt[] - Prompt displayed to the user
  * @const char error_msg[] =  Error message
  *
  * Return: 0 on success or 1 on failure.
  */

int main(void)
{
	char *command = NULL;
	size_t command_length = 0;
	ssize_t num_bytes;
	char *token;
	char *args[2];
	const char prompt[] = "Liza_Asa_Shell$ ";
	const char error_msg[] = "Sorry, No such file or directory\n";
	pid_t pid;

	while (1)
	{
		/* Display prompt */
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

		/* Read command line */
		num_bytes = getline(&command, &command_length, stdin);

		if (num_bytes == -1)
		{
			/* Handle end of file (Ctrl+D) */
			write(STDOUT_FILENO, "\n", 1);
			free(command);
			break;
		}

		/* Remove trailing newline character */
		command[num_bytes - 1] = '\0';

		token = strtok(command, " ");/* Tokenize command line */
		if (token == NULL)
		{
			continue;  /* Empty command, display prompt again */
		}

		args[0] = token;  /* Set up arguments for execve */
		args[1] = NULL;

		pid = fork(); /* Fork a child process */

		if (pid < 0)
		{
			/* Forking error, display error message and exit */
			write(STDOUT_FILENO, error_msg, sizeof(error_msg) - 1);
			free(command);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve(token, args, NULL); /* Handling Child process */

	    write(STDOUT_FILENO, error_msg, sizeof(error_msg) - 1);
	    free(command);
	    exit(EXIT_FAILURE)
		}
		else
		{
			int status; /* Handling Parent process */

			waitpid(pid, &status, 0);
		}
	}
	return (0);
}

