#include "shell.h"

/**
 * _strlen - return the length of a string
 *
 * @s: char to check string
 *
 * Return: 0 is success
 */
int _strlen(char *s)
{
	int x = 0;


	for (; *s++;)
		x++;
	return (x);
}

