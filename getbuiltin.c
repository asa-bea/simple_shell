#include "shell.h"

/**
 * getbuiltin - Retrieves the corresponding builtin function for a command.
 * @command: The command to search for.
 *
 * Return: A pointer to the corresponding builtin function, or NULL.
 */
void (*getbuiltin(char *command))(args_t *)
{
	builtin_t builtins[] = {
		{"exit", _exit},
		{NULL, NULL}
	};
	int i;

	for (i = 0; builtins[i].command != NULL; i++)
	{
		if (_strcmp(command, builtins[i].command) == 0)
			return (builtins[i].f);
	}
	return (NULL);
}

