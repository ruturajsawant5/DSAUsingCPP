#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono> // For measuring time
#include <algorithm> // For sorting array
#include <climits>

using namespace std;
using namespace chrono; // For time functions

// Function for Binary Search
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at mid
        if (arr[mid] == target) {
            return mid; // Element found
        }

        // If target is smaller, ignore the right half
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // If target is larger, ignore the left half
        else {
            left = mid + 1;
        }
    }

    return -1; // Target not found
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
				   
    // Sort array before performing binary search
    auto start = high_resolution_clock::now();
    sort(arr, arr + numElements);
    auto stop = high_resolution_clock::now();
    auto durationSort = duration_cast<microseconds>(stop - start);
    cout << "Sort runtime: " << durationSort.count() << " microseconds" << endl;

    // Measure runtime of Binary Search
    start = high_resolution_clock::now(); // Start time for Binary Search
    int binaryResult = binarySearch(arr, numElements, target);
    stop = high_resolution_clock::now(); // End time for Binary Search
    auto durationBinary = duration_cast<microseconds>(stop - start); // Duration in microseconds

    if (binaryResult != -1) {
        cout << "Binary Search: Element found at index " << binaryResult << endl;
    } else {
        cout << "Binary Search: Element not found!" << endl;
    }
    cout << "Binary Search runtime: " << durationBinary.count() << " microseconds" << endl;

    // Clean up dynamically allocated memory
    delete[] arr;

    return 0;
}
