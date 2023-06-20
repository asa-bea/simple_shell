#include "shell.h"

/** buffer: A pointer to a character that will be used to store the user input.
   * @buffer_size: The size of the buffer allocated for user input.
   * @input_length: A signed integer to store the length of the user input.
   * @child_pid: A process ID to store the child process ID.
   * @status: An integer to store the exit status or termination signal of the
   * child process
   *
   * return : 0 (successful)
*/


int main(void)
{
   	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t input_length;
	while (1)
    {
    	write(STDOUT_FILENO, "$ ", 2);  /* Displays the prompt */

    	input_length = getline(&buffer, &buffer_size, stdin);

    	if (input_length == -1) {
        	write(STDOUT_FILENO, "\n", 1); /* Handle EOF condition*/
        	break;
    	}

    	buffer[input_length - 1] = '\0';  /* Remove trailing newline char*/


	free(buffer);

	return (0);
}
}
