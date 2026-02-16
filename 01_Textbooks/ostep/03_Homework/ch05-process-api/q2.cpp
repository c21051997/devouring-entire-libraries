#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <iostream>

int main() {
    
    int fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd < 0) {
        perror("open failed");
        return 1;
    }
    
    int rc = fork();
    
    if (rc < 0) {
        perror("fork failed");
        return 1;
    } else if (rc == 0) {
        std::cout << "Child fd: " << fd << '\n';
        char* child_msg = "Child: writing to the shared file fd\n";

        for (int i = 0; i < 5; ++i) {
            write(fd, child_msg, strlen(child_msg));
        }
        std::cout << "Child finished writing\n";

    } else {
        std::cout << "Parent fd: " << fd << '\n';

        char* parent_msg = "Parent: also writing to the same fd\n";

        for (int i = 0; i < 5; ++i) {
            write(fd, parent_msg, strlen(parent_msg));
        }
        wait(nullptr);
        
        close(fd);
        std::cout << "Parent finished\n";
    }

    return 0;
}