/**
 * Include the necessary header files:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Define a constant for the maximum length of a command
#define MAX_COMMAND_LENGTH 100

//Define a function to handle the execution of commands

void execute_command(char *command) {
    // Check if the command is "exit"
    if (strcmp(command, "exit") == 0) {
        exit(0);
    }
    
    // Check if the command is "env"
    if (strcmp(command, "env") == 0) {
        extern char **environ;
        for (char **env = environ; *env != NULL; env++) {
            printf("%s\n", *env);
        }
        return;
    }
    
    // Fork a child process
    pid_t pid = fork();
    
    if (pid < 0) {
        // Error occurred while forking
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        char *args[] = {command, NULL};
        execvp(args[0], args);
        
        // If execvp returns, an error occurred
        perror("execvp");
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    
    while (1) {
        // Display prompt
        printf("simple_shell$ ");
        
        // Read command from user
        if (fgets(command, sizeof(command), stdin) == NULL) {
            // End of file (Ctrl+D) condition
            printf("\n");
            exit(0);
        }
        
        // Remove newline character from the end of the command
        command[strcspn(command, "\n")] = '\0';
        
        // Execute the command
        execute_command(command);
    }
    
    return 0;
}


