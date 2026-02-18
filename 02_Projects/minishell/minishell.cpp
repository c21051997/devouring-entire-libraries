#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>     // For Process API [cite: 15, 179]
#include <sys/wait.h>   // For process control [cite: 162]
#include <sys/time.h>   // For measurement [cite: 1028]

int main() {
    std::string userInput;

    while (true) {
        std::cout << "os-manager> ";
        if (!(std::cin >> userInput)) break;

        // --- STEP 1: RECORD ARRIVAL ---
        // TODO: Use gettimeofday() here to mark the "arrival time" (T_arrival)
        // reference: Chapter 7.2 [cite: 1083, 1084]
        struct timeval start, end;
        gettimeofday(&start, nullptr);

        // --- STEP 2: CREATE PROCESS ---
        // TODO: Call the "strangest routine" to create a twin process
        // reference: Chapter 5.1 [cite: 15, 16]
        pid_t rc = fork();

        if (rc < 0) {
            // handle error
            perror("Fork failed!");
            return 1;
        } 
        else if (rc == 0) {
            // --- STEP 3: TRANSFORMATION ---
            // TODO: Use a member of the exec() family to run userInput
            // Note: execvp() is usually easiest for shell-like behavior
            // reference: Chapter 5.3 [cite: 179, 254]
            char* args[2];
            args[0] = (char*)userInput.c_str();
            args[1] = nullptr;

            execvp(args[0], args);
            
            perror("execvp failed");
            return 1;
        } 
        else {
            // --- STEP 4: CONTROL ---
            // TODO: In the parent, wait for the specific child to finish
            // reference: Chapter 5.2 [cite: 162]
            waitpid(rc, nullptr, 0);

            // --- STEP 5: PERFORMANCE METRICS ---
            // TODO: Use gettimeofday() again to mark "completion time" (T_completion)
            gettimeofday(&end, nullptr);

            // TODO: Calculate and print Turnaround Time (T_completion - T_arrival)
            // reference: Chapter 7.2 [cite: 1084, 1455]
            double turnaround = (end.tv_sec - start.tv_sec) + 
                                (end.tv_usec - start.tv_usec) / 1000000.0;
            
            std::cout << "  [Parent] Child " << rc << " finished." << std::endl;
            std::cout << "  [Metric] Turnaround Time: " << turnaround << " seconds." << std::endl;
        }
    }

    return 0;
}