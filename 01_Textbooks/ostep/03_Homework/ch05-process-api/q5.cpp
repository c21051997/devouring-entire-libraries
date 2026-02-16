#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <iostream>

int main() {
    int rc = fork();

    if (rc < 0) {
        perror("fork failed");
        return 0;
    } else if (rc == 0) {
        std::cout << "hello\n"; 
    } else {
        int status;
        waitpid(rc, &status, 0);
        std::cout << "goodbye\n";
    }

    return 0;
}