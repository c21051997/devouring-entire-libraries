#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int rc = fork();

    if (rc < 0) {
        perror("fork failed");
        exit(1);
    } else if (rc == 0) {
        // --- CHILD PROCESS ---
        
        // Example 1: execl (List arguments individually, ends with NULL)
        // execl("/bin/ls", "ls", "-l", NULL);

        // Example 2: execp (Uses the PATH variable so you don't need "/bin/")
        // execlp("ls", "ls", "-l", NULL);

        // Example 3: execv (Uses an Array/Vector of strings)
        char *myargs[3];
        myargs[0] = "ls";
        myargs[1] = "-l";
        myargs[2] = NULL;
        execv("/bin/ls", myargs);

        // Example 4: execvp (Array + Path search)
        // execvp("ls", myargs);

        // If any of these succeed, the code below NEVER runs.
        perror("exec failed");
        exit(1);
    } else {
        // --- PARENT PROCESS ---
        wait(NULL);
        printf("Child finished execution.\n");
    }
    return 0;
}