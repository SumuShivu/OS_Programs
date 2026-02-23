#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>   // For EXIT_FAILURE and EXIT_SUCCESS
#include <sys/wait.h> // For waitpid (optional)

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid == -1) {
        // Error handling
        perror("fork failed");
        
    } 
    else if (pid == 0) {
        // Code executed by the child process
        printf("Child proces: PID = %d, Parent PID = %d\n",
               getpid(), getppid());
        
    } 
    else {
        // Code executed by the parent process
        printf("Parent process: PID = %d, Child PID = %d\n",
               getpid(), pid);

        // Optional: Wait for child to finish
        //int status;
        // waitpid(pid, &status, 0);

        
    }
}