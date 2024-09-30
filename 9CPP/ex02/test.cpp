#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <algorithm>  // For std::swap
#include <stdlib.h>

int main(int ac, char **av) {
    const int N = atoi(av[1]);  // Change this to the number of unique numbers you want
    int numbers[N];

    // Initialize the array with values from 1 to N
    for (int i = 0; i < N; ++i) {
        numbers[i] = i + 1;
    }

    // Shuffle the array to generate unique random order
    srand(time(0));  // Seed the random number generator
    for (int i = N - 1; i > 0; --i) {
        int j = rand() % (i + 1);  // Random index from 0 to i
        std::swap(numbers[i], numbers[j]);
    }

    // Print the unique random numbers
    for (int i = 0; i < N; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}