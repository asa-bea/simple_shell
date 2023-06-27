#include "shell.h"

/**
  *free_arguments - a functioin that frees allocated mem
  *@arguments: parameter passed to free_argument
  */

void free_arguments(args_t *arguments)
{
	int i = 0;

	if (arguments->token_array != NULL)
		free(arguments->command);


	if (arguments->token_array != NULL)
	{
		i = 0;
		while (arguments->token_array[i] != NULL)
		{
			free(arguments->token_array[i]);
			i++;
		}
		free(arguments->token_array);
	}
}
