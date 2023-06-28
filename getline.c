#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * my_getline - Custom getline function
 * @lineptr: A pointer to a pointer that will store the address of the buffer
 * containing the read line.
 * @n: A ptr to a variable that holds the size of the buffer pointed to lineptr
 * @stream:A pointer to the FILE stream from which the line will be read
 * Description: Reads characters from standard input into a buffer
 *              using a static variable and minimizes the number of
 *              read system calls.
 *
 * Return: Line read from input, or NULL on failure or EOF.
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t bufsize = 128;
	ssize_t characters = 0;
	char *buffer = NULL, *temp;
	ssize_t bytes_read;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		return (-1);

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1); /* Invalid arguments*/
	while ((bytes_read = read(fileno(stream), &buffer[characters], 1)) > 0)
	{
		if (characters >= bufsize)
		{
			bufsize += 128;
			temp = malloc(bufsize * sizeof(char));
			if (temp == NULL)
			{
				free(buffer);
				return (-1);
			}
			buffer = temp;
		}
		characters++;

		if (buffer[characters - 1] == '\n')
			break;
	}

	if (characters == 0 && bytes_read == 0)
		return (-1);

	buffer[characters] = '\0';

	*lineptr = buffer;
	*n = bufsize;

	return (characters);
}
