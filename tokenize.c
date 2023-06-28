#include "shell.h"

/**
  * tokenize - handles tokenization
  * @argument: token function argument
  */

void tokenize(args_t *argument)
{
	int n_tokens = 0;
	char *cmd_cpy, *token;
	int i = 0;

	cmd_cpy = malloc(sizeof(char) * (_strlen(argument->command) + 1));

	_strcpy(cmd_cpy, argument->command);
	token = _strtok(cmd_cpy, " ");

	while (token != NULL)
	{
		n_tokens++;
		token = _strtok(NULL, " ");
	}

	argument->token_array = malloc(sizeof(char *) * (n_tokens + 1));

	if (argument->token_array == NULL)
	{
		free(cmd_cpy);
		return;
	}
	_strcpy(cmd_cpy, argument->command);
	token = _strtok(cmd_cpy, " ");

	while (token != NULL)
	{
		argument->token_array[i] = malloc(
				sizeof(char) * (_strlen(token) + 1));

		_strcpy(argument->token_array[i], token);
		i++;
		token = _strtok(NULL, " ");
	}
	argument->token_array[i] = NULL;

	free(cmd_cpy);
}
