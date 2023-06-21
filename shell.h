#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#define BUFFER_SIZE 1024

#endif /* Asabea & Liza */
