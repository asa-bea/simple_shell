#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

char* find_command_path(char* command)
char** parse_arguments(char* command);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#define BUFFER_SIZE 1024

#endif /* Asabea & Liza */
