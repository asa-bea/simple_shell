#include "shell.h"

void (*getbuiltin(char *command))(args_t *)
{
	builtin_t builtins[] = {
		{"exit", _exit},
		{NULL, NULL}
	};
	int i;

	for (i = 0; builtins[i].command != NULL; i++)
	{
		if (_strcmp{command, builtins[i].command} == 0)
				return (builtins[i].f);
	}
	return (NULL);
}
