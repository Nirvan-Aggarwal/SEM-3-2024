#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = getpid();  // Declare variable for process ID

    // Get and print the current process ID
    printf("Parent Process ID: %d\n", pid);

    // Create a child process
    pid_t child_pid = fork();

    if (child_pid < 0) {
        // Fork failed
        perror("fork");
        
    } else if (child_pid == 0) {
        // This block is executed by the child process
        printf("Child Process ID: %d\n", getpid());
        printf("Parent Process ID (from child): %d\n", getppid());
    } else {
        // This block is executed by the parent process
        printf("In Parent Process: Child Process ID: %d\n", child_pid);
    }

    // End of the program
    return 0;
}