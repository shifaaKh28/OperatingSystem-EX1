#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

#define PHONEBOOK "phonebook.txt"

// Main function to search for a phone number in the phonebook
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        // If not, print usage information and return an error code
        fprintf(stderr, "Usage: %s <first_name> <last_name>\n", argv[0]);
        return 1;
    }

    // Dynamically allocate memory for the concatenated name
    size_t name_len = strlen(argv[1]) + strlen(argv[2]) + 2; // +2 for space and null terminator
    char *name = (char *)malloc(name_len * sizeof(char));
    if (name == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    snprintf(name, name_len, "%s %s", argv[1], argv[2]);

    // Define pipes for inter-process communication
    int pipe1[2], pipe2[2], pipe3[2];

    // Create a pipe for communication between processes
    pipe(pipe1);

    // Create a child process using fork
    if (fork() == 0) {
        // Redirect the standard output to the write end of pipe1
        dup2(pipe1[1], 1);
        // Close unused file descriptors
        close(pipe1[0]);
        close(pipe1[1]);
        // Execute the 'cat' command to read the phonebook file
        execlp("cat", "cat", PHONEBOOK, NULL);
        // If execlp fails, print an error message and exit
        perror("execlp failed");
        exit(1);
    }

    // Close the write end of pipe1 in the parent process
    close(pipe1[1]);

    // Create another pipe for communication between processes
    pipe(pipe2);

    // Create a child process using fork
    if (fork() == 0) {
        // Redirect the standard input from the read end of pipe1
        // and redirect the standard output to the write end of pipe2
        dup2(pipe1[0], 0);
        dup2(pipe2[1], 1);
        // Close unused file descriptors
        close(pipe1[0]);
        close(pipe2[0]);
        close(pipe2[1]);
        // Execute the 'grep' command to search for the specified name
        execlp("grep", "grep", name, NULL);
        // If execlp fails, print an error message and exit
        perror("execlp failed");
        exit(1);
    }

    // Close the read end of pipe1 in the parent process
    close(pipe1[0]);

    // Close the write end of pipe2 in the parent process
    close(pipe2[1]);

    // Create another pipe for communication between processes
    pipe(pipe3);

    // Create a child process using fork
    if (fork() == 0) {
        // Redirect the standard input from the read end of pipe2
        // and redirect the standard output to the write end of pipe3
        dup2(pipe2[0], 0);
        dup2(pipe3[1], 1);
        // Close unused file descriptors
        close(pipe2[0]);
        close(pipe3[0]);
        close(pipe3[1]);
        // Execute the 'sed' command to modify the output format
        execlp("sed", "sed", "s/,/ /", NULL);
        // If execlp fails, print an error message and exit
        perror("execlp failed");
        exit(1);
    }

    // Close the read end of pipe2 in the parent process
    close(pipe2[0]);

    // Close the write end of pipe3 in the parent process
    close(pipe3[1]);

    // Create a child process using fork
    if (fork() == 0) {
        // Redirect the standard input from the read end of pipe3
        // and redirect the standard output to the standard output of the parent process
        dup2(pipe3[0], 0);
        // Close unused file descriptors
        close(pipe3[0]);
        // Execute the 'awk' command to print the phone number and exit after the first match
        execlp("awk", "awk", "{print $3; exit}", NULL);
        // If execlp fails, print an error message and exit
        perror("execlp failed");
        exit(1);
    }

    // Close the read end of pipe3 in the parent process
    close(pipe3[0]);

    // Wait for all child processes to finish
    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    // Free dynamically allocated memory
    free(name);

    return 0; // Return success
}
