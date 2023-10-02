#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Create a shared integer variable in shared memory and initialize it to 1
    int* shared_counter = (int*)malloc(sizeof(int));
    *shared_counter = 1;

    // Launch a child process
    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Error creating child process." << std::endl;
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        int limit;

        // Ask the user for a value between 10 and 20
        do {
            std::cout << "Enter a value between 10 and 20: ";
            std::cin >> limit;
        } while (limit < 10 || limit > 20);

        // Increment the value in the shared variable until it reaches the specified limit
        for (int i = 1; i <= limit; ++i) {
            (*shared_counter)++;
            std::cout << "Incremented: " << *shared_counter << std::endl;
        }

        // Terminate the child process
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        // Wait until the child process terminates
        waitpid(pid, NULL, 0);

        // Decrement the value in the shared variable until it reaches 1
        while (*shared_counter > 1) {
            (*shared_counter)--;
            std::cout << "Decremented: " << *shared_counter << std::endl;
        }

        // Release the shared memory
        free(shared_counter);
    }

    return 0;
}