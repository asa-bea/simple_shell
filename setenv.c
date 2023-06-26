#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * setenv - Set or modify an environment variable
 * @variable: The name of the variable
 * @value: The value to be assigned to the variable
 * @overwrite: Flag to indicate whether to overwrite
 *             an existing variable
 *
 * Return: 0 on success, -1 on failure
 */
int setenv(const char *variable, const char *value, int overwrite)
{
	if (overwrite == 0 && getenv(variable) != NULL)
	{
	fprintf(stderr, "Failed to set environment variable: %s
			(already exists)\n", variable);
	return (-1);
	}
	if (setenv(variable, value, 1) != 0)
	{
	fprintf(stderr, "Failed to set environment variable: %s\n", variable);
	return (-1);
	}
	return (0);
}

/**
 * unsetenv - Remove an environment variable
 * @variable: The name of the variable to be removed
 *
 * Return: 0 on success, -1 on failure
 */
int unsetenv(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		fprintf(stderr, "Failed to unset environment variable: %s\n", variable);
		return (-1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Invalid number of arguments\n");
		return (1);
	}

	if (strcmp(argv[1], "setenv") == 0)
	{
	if (argc < 4)
	{
		fprintf(stderr, "Invalid number of arguments\n");
		return (1); /* Return non-zero on failure */
	}

	const char *variable = argv[2];
	const char *value = argv[3];

	if (setenv(variable, value, 1) != 0)
	{
		return (1); /* Return non-zero on failure */
	}
	}
	else if (strcmp(argv[1], "unsetenv") == 0)
	{
	if (argc < 3)
	{
		fprintf(stderr, "Invalid number of arguments\n");
		return (1);
	}

	const char *variable = argv[2];

	if (unsetenv(variable) != 0)
	{
		return (1);
	}
	}
	else
	{
	fprintf(stderr, "Invalid command: %s\n", argv[1]);
	return (1);
	}

	return (0);
}

