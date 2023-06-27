#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10

/**
 * check_command_existence - Check if a command exists in the PATH.
 * @command: The command to check.
 *
 * Return: 1 if the command exists, 0 otherwise.
 */
int check_command_existence(char *command)
{
	char *path_env = getenv("PATH");
	char *path = strtok(path_env, ":");
	char full_path[1024];

	while (path != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", path, command);
		if (access(full_path, F_OK) == 0)
			return (1);

		path = strtok(NULL, ":");
	}

	return (0);
}

/**
 * tokenize_command - Tokenize a command into arguments.
 * @command: The command to tokenize.
 * @args: An array to store the arguments.
 *
 * This function tokenizes the command string based on spaces and stores
 * the resulting arguments in the 'args' array. The array is terminated with
 * a NULL pointer.
 */
void tokenize_command(char *command, char **args)
{
	char *token;
	int arg_count = 0;

	token = strtok(command, " ");

	while (token != NULL && arg_count < MAX_ARGS)
	{
		args[arg_count] = strdup(token);
		arg_count++;

		token = strtok(NULL, " ");
	}

	args[arg_count] = NULL;
}

/**
 * execute_child_process - Execute a child process using execvp.
 * @args: The arguments for the command.
 *
 * This function is called in the child process to execute the command
 * using the execvp system call.
 */
void execute_child_process(char **args)
{
	if (execvp(args[0], args) == -1)
	{
		perror("execvp");
		exit(1);
	}
}

/**
 * execute_command - Execute a command in the shell.
 * @command: The command to execute.
 *
 * This function executes the specified command in the shell. It checks
 * if the command exists, forks a child process, and executes the command
 * in the child process using execvp. The parent process waits for the
 * child process to complete.
 */
void execute_command(char *command)
{
	char *args[MAX_ARGS + 1];
	pid_t child_pid;

	tokenize_command(command, args);

	if (args[0] == NULL)
	{
		/* Empty command */
		return;
	}

	if (!check_command_existence(args[0]))
	{
		fprintf(stderr, "Command not found: %s\n", args[0]);
		return;
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return;
	}
	else if (child_pid == 0)
	{
		/* Child process */
		execute_child_process(args);
	}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}

