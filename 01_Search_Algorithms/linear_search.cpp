#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono> // For measuring time
#include <algorithm> // For sorting array
#include <climits>

using namespace std;
using namespace chrono; // For time functions

// Function for Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <number_of_elements>" << endl;
        return 1;
    }

    // Convert command line argument to an integer
    int numElements = atoi(argv[1]);

    // Seed random number generator
    srand(time(0));

    // Create an array of random integers
    int* arr = new int[numElements];
    for (int i = 0; i < numElements; i++) {
        arr[i] = rand() % INT_MAX;
    }
#if 0
    // Print the generated array
    cout << "Generated array: ";
    for (int i = 0; i < numElements; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
#endif
    // Generate a random index to search for
    int randomIndex = rand() % numElements;
    int target = arr[randomIndex]; // The value to search for

    // Measure runtime of Linear Search
    auto start = high_resolution_clock::now(); // Start time for Linear Search
    int linearResult = linearSearch(arr, numElements, target);
    auto stop = high_resolution_clock::now(); // End time for Linear Search
    auto durationLinear = duration_cast<microseconds>(stop - start); // Duration in microseconds

    if (linearResult != -1) {
        cout << "Linear Search: Element found at index " << linearResult << endl;
    } else {
        cout << "Linear Search: Element not found!" << endl;
    }
    cout << "Linear Search runtime: " << durationLinear.count() << " microseconds" << endl;

    // Clean up dynamically allocated memory
    delete[] arr;

    return 0;
}
