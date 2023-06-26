#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

char* find_command_path(char* command);
char** parse_arguments(char* command);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

int execute_command(char *buffer);
int execute_command(char **args);

void executeCommand(char *command);

void display_error();
void wait_for_child(pid_t pid, int* status);

void my_function(void);

char *read_line(void);
char **split_line(char *line);
void execute(char **args);
int main(void);

char *read_line(void);
char **split_line(char *line);
void execute(char **args);
void shell_exit(char **args);

int setenv(const char *variable, const char *value, int overwrite);
int unsetenv(const char *variable);

int main(int argc, char *argv[]);

#define BUFFER_SIZE 1024

#endif /* Asabea & Liza */
