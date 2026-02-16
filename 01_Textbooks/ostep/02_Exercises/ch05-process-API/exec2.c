#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main (int argc, char* argv[]) {
    printf("hello (pid:%d)\n", (int) getpid());
    int rc = fork();

    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child: redirect standard output to a file
        close(STDOUT_FILENO);
        open("exec2.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        char* myargs[3];

        myargs[0] = strdup("wc"); // program: "wc"
        myargs[1] = strdup("exec2.c"); // arg: input file
        myargs[2] = NULL; // mark end of array

        execvp(myargs[0], myargs); // runs word count
        printf("this shouldn’t print out");
    } else {
        // parent process
        int rc_wait = wait(NULL);
        printf("parent of %d (pid:%d)\n", rc, (int) getpid());
    }

    return 0;
}