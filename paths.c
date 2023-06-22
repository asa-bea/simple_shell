#include "shell.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

#define MAX_ARGS 10
#define PATH_MAX_LENGTH 1024

int main(){

// Function to find the path of the command using the PATH environment variable
char* find_command_path(char* command)

	char* path = getenv("PATH");
         char* dir = strtok(path, ":");

    char cmd_path[PATH_MAX_LENGTH];

    while (dir != NULL) {
        strncpy(cmd_path, dir, PATH_MAX_LENGTH);
        strncat(cmd_path, "/", PATH_MAX_LENGTH - strlen(cmd_path) - 1);
        strncat(cmd_path, command, PATH_MAX_LENGTH - strlen(cmd_path) - 1);

        // Check if the constructed path is executable
        if (access(cmd_path, X_OK) == 0) {
            return strdup(cmd_path);
        }

        dir = strtok(NULL, ":");
    }

    return "";
}
}
