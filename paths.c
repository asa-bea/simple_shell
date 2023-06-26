#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

#define MAX_ARGS 10
#define PATH_MAX_LENGTH 1024

/**
  * @find_command_path -  Function to find the path of the command using the
  * PATH environment variable
  */
int main(void)
{

char* find_command_path(char* command)
{
    char *path = getenv("PATH");  // Get the value of the PATH environment variable
    char *dir = strtok(path, ":");  // Tokenize the path using ":" as the delimiter

    char cmd_path[PATH_MAX_LENGTH];  // Buffer to store the constructed command path

    while (dir != NULL) {
        size_t dir_length = strlen(dir);
        size_t cmd_length = strlen(command);

        if (dir_length + 1 + cmd_length < PATH_MAX_LENGTH)
	{
		memcpy(cmd_path, dir, dir_length);
		cmd_path[dir_length] = '/';  // Append "/" to the buffer
            memcpy(cmd_path + dir_length + 1, command, cmd_length);
            cmd_path[dir_length + 1 + cmd_length] = '\0';

            /* Check if the constructed path is executable */
            if (access(cmd_path, X_OK) == 0)
	    {
                return strdup(cmd_path);
            }
        }

        dir = strtok(NULL, ":");  /* Move to the next directory in the path */
    }

    return (NULL);  /* if Command not found in any directory of the PATH */
}
}
