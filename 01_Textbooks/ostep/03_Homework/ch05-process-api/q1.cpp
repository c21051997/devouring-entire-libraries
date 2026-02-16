#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

int main() {
    
    int x = 100;
    int rc = fork();
    
    if (rc < 0) {
        perror("fork failed");
        return 1;
    } else if (rc == 0) {
        std::cout << "Child initial: " << x << '\n';

        x = 1;

        std::cout << "Child after change: " << x << '\n'; 
    } else {
        std::cout << "Parent initial: " << x << '\n';

        x = 20;

        std::cout << "Parent after change: " << x << '\n'; 
    }

    return 0;
}