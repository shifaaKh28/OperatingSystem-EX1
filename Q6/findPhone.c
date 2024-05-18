#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define PHONEBOOK "phonebook.txt"

// Function to execute a command with specified input and output file descriptors
void execute_command(char *command, char **args, int input_fd, int output_fd) {
    if (fork() == 0) { // Create a new process
        if (input_fd != 0) { // If input_fd is not the standard input
            dup2(input_fd, 0); // Duplicate input_fd to standard input
            close(input_fd); // Close the original input_fd
        }
        if (output_fd != 1) { // If output_fd is not the standard output
            dup2(output_fd, 1); // Duplicate output_fd to standard output
            close(output_fd); // Close the original output_fd
        }
        execvp(command, args); // Execute the command
        perror("execvp failed"); // If execvp fails, print an error message
        exit(1); // Exit the child process with an error code
    }
}


int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc < 2) {
        // Print usage information if not enough arguments are provided
        fprintf(stderr, "Usage: %s <name>\n", argv[0]);
        return 1;
    }

    // Define pipes for inter-process communication
    int pipe1[2], pipe2[2];

    // Create a pipe for communication between processes
    pipe(pipe1);

    // Execute the 'cat' command to read the phonebook file
    execute_command("cat", (char *[]){"cat", PHONEBOOK, NULL}, 0, pipe1[1]);
    close(pipe1[1]); // Close the write end of the pipe

    // Create another pipe for communication between processes
    pipe(pipe2);

    // Execute the 'grep' command to search for the specified name
    execute_command("grep", (char *[]){"grep", argv[1], NULL}, pipe1[0], pipe2[1]);
    close(pipe1[0]); // Close the read end of the first pipe
    close(pipe2[1]); // Close the write end of the second pipe

    // Execute the 'awk' command to print the phone number
    execute_command("awk", (char *[]){"awk", "-F,", "{print $2}", NULL}, pipe2[0], 1);
    close(pipe2[0]); // Close the read end of the second pipe

    // Wait for all child processes to finish
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    return 0; // Return success
}
