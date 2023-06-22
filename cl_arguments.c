#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10

int parse_arguments(char* command, char** args) {
    char* token;
    int arg_count = 0;

    // Tokenize command line
    token = strtok(command, " ");

    if (token == NULL) {
        // Empty command
        return 0;
    }

    while (arg_count < MAX_ARGS) {
        args[arg_count] = strdup(token);  // Allocate memory and copy token
        arg_count++;

        token = strtok(NULL, " ");
        if (token == NULL) {
            break;
        }
    }

    // Ensure the last element of args is NULL to terminate the argument list
    args[arg_count] = NULL;

    return arg_count;
}

int main() {
    // Example usage
    char command[] = "ls -l -a";
    char* args[MAX_ARGS + 1];  // +1 to accommodate the NULL terminator
    int arg_count = parse_arguments(command, args);

    if (arg_count > 0) {
        int i;
        for (i = 0; i < arg_count; i++) {
            char arg_index = '0' + i;
            write(1, "Argument ", 9);
            write(1, &arg_index, 1);
            write(1, ": ", 2);
            write(1, args[i], strlen(args[i]));
            write(1, "\n", 1);
        }
    } else {
        write(1, "No arguments found.\n", 20);
    }

    return 0;
}

