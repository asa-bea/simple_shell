#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
  * _atoi - Entry point
  * Description - function converting a string
  * @s: string to be converted
  * Return: converted integer value (successful)
  */

int _atoi(char *s)
{
	int a, b, n, len, y, digit;

	a = 0;
	b = 0;
	n = 0;
	len = 0;
	y = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (a < len && y == 0)
	{
		if (s[a] == '-')
			++b;

		if (s[a] >= '0' && s[a] <= '9')
		{
			digit = s[a] - '0';
			if (b % 2)
				digit = -digit;
			n = n * 10 + digit;
			y = 1;
			if (s[a + 1] < '0' || s[a + 1] > '9')
				break;
			y = 0;
		}
		a++;
	}

	if (y == 0)
		return (0);

	return (n);
}

/**
  *
  */
 int isnumber(char *str)
{
	int i;
	int len = _strlen(str);

	for (; i < len; i++)
	{
		if (i == 0 && str[i] == '-')
			continue;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
