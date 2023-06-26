#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <math.h>
#include <dirent.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>
#include <errno.h>

/**
  * main - entry point
  * @command - command
  * @arg: a string generated from getline that holds arguments
  */

char *find_command_path(char *command);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int execute_command(char *buffer);
<<<<<<< HEAD
void executeCommand(char *command);
void display_error(void);
void wait_for_child(pid_t pid, int *status);
int parse_arguments(char *command, char **args);
=======
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
>>>>>>> ff139e65af22a513291b45f442ecf09083f8a02b

#define BUFFER_SIZE 1024
#define BUFFER_SIZE_WRITE 1024
#define MAX_WORD_COUNT 100
#define NEG_ONE -1
#define REG_FLAG 0
#define OR_FLAG 1
#define AND_FLAG 2
#define CHAIN_FLAG 3
#define BAS_CHANGE_LOWER 1
#define BAS_CHANGE_UNSIG 2
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE_NAME ".ss_history"
#define HIST_SIZE_MAX 4096
#define SET_INFO


#endif /* Asabea & Liza */
