#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * _strtok - Read a line from standard input
 * @str:  A pointer to the string to be tokenized.
 * @delim: A pointer to a null-terminated string containing the delimiters
 * used for tokenization
 * Description: Reads characters from standard input into a buffer until
 *              a newline character is encountered.
 *
 * Return: The line read from input, or NULL on failure or EOF.
 */
char *_strtok(char *str, const char *delim)
{
	static char *saved_token;
	char *token;

	if (str == NULL && saved_token == NULL)
		return (NULL);

	if (str != NULL)
		saved_token = str;

	saved_token += _strspn(saved_token, (char *) delim);

	if (*saved_token == '\0')
		return (NULL);

	token = saved_token;

	saved_token = _strpbrk((char *) saved_token, (char *) delim);

	if (saved_token != NULL)
	{
		*saved_token = '\0';
		saved_token++;
	}

	return (token);
}
