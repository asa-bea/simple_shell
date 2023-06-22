#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    char* command = NULL;
    size_t command_length = 0;
    ssize_t num_bytes;
    char* token;
    char* args[2];
    const char prompt[] = "Liza_Asa_Shell$ ";
    const char error_msg[] = "Sorry, No such file or directory\n";

    pid_t pid;

    while (1) {
        // Display prompt
        write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

        // Read command line
         num_bytes = getline(&command, &command_length, stdin);

        if (num_bytes == -1) {
            // Handle end of file (Ctrl+D)
            write(STDOUT_FILENO, "\n", 1);
            free(command);
            break;
        }

        // Remove trailing newline character
        command[num_bytes - 1] = '\0';

        // Tokenize command line
        token = strtok(command, " ");

        if (token == NULL) {
            // Empty command, display prompt again
            continue;
        }

        // Set up arguments for execve
        args[0] = token;
        args[1] = NULL;

        // Fork a child process
         pid = fork();

        if (pid < 0) {
            // Forking error, display error message and exit
            write(STDOUT_FILENO, error_msg, sizeof(error_msg) - 1);
            free(command);
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execve(token, args, NULL);

            // If execve returns, an error occurred
            write(STDOUT_FILENO, error_msg, sizeof(error_msg) - 1);
            free(command);
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

