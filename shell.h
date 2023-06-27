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
  * struct args_s - structs typedef function
  * @token_array: array of strings
  * @command: a string
  */
typedef struct args_s
{
	char **token_array;
	char *command;
} args_t;



/**
  * struct builtin_s - structs typedef function
  * @command: a string
  * @f: function pointer
  */

typedef struct builtin_s
{
	char *command;
	void (*f)(args_t *);
} builtin_t;


/**
 * builtin_exit - Exit the shell.
 * @arg: The exit code as a string.
 *
 * This function is a built-in command that is executed when
 * It terminates the shell process with the specified exit
 * exit code is used.
 */
typedef struct builtin_exit
{
	char *args;
}status;


int _atoi(char *s);
int _strcmp(char *str1, char *str2);
void (*getbuiltin(char *command))(args_t *);
char *find_command_path(char *command);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void execute_command(char *command);
void display_error(void);
void wait_for_child(pid_t pid, int *status);
int parse_arguments(char *command, char **args);
void execCommand(args_t *arguments);
void executeCommand(char *command);
void wait_for_child(pid_t pid, int *status);
void my_function(void);
char *_strcpy(char *dest, char *src);
char *read_line(void);
int _strlen(char *s);
char **split_line(char *line, char *delimiters);
void execute(char **args);
void shell_exit(char **args);
int setenv(const char *variable, const char *value, int overwrite);
int unsetenv(const char *variable);
void tokenize(args_t *argument);
void free_arguments(args_t *argumentsi);
void handle_non_interactive(args_t *arguments);
void builtin_exit(char *arg);
int check_command_existence(char *command);

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
