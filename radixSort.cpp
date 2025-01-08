#include <iostream>
using namespace std;

// Function to perform Counting Sort based on digit place (1s, 10s, 100s, etc.)
void countSort(int arr[], int n, int exponent) {
    // Your code here
    const int base = 10; 
    int output[n]; 
    int count[base] = {0}; 

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exponent) % base;
        count[digit]++;
    }

    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exponent) % base;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    // Your code here
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    for (int exponent = 1; maxElement / exponent > 0; exponent *= 10) {
        countSort(arr, n, exponent);
    }
}

// Function to initiate the Radix Sort process.
void processRadixSort(int arr[], int n) {
    // Your code here
    radixSort(arr, n);
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to dynamically allocate an array and fill it with random values.
void fillDynamicArrayWithRandomValues(int** arr, int* n) {
    cout << "Enter the size of the array: ";
    cin >> *n;
    *arr = new int[*n];
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < *n; i++) {
        (*arr)[i] = rand() % 1000; // Fill with random numbers between 0 and 999
    }
}

int main() {
    int* arr;
    int n;
    fillDynamicArrayWithRandomValues(&arr, &n);
    cout << "Unsorted array: ";
    displayArray(arr, n);
    processRadixSort(arr, n);
    cout << "Sorted array: ";
    displayArray(arr, n);
    delete[] arr; // Deallocate dynamically allocated memory
    return 0;
}
