#include <iostream>
using namespace std;

// Function to swap two elements in an array
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Selection sort function to sort the array into descending order
void SelectionSortDescendTrace(int numbers[], int numElements) {
    for (int i = 0; i < numElements - 1; ++i) {
        int maxIndex = i;
        // Find the index of the maximum element in the unsorted part of the array
        for (int j = i + 1; j < numElements; ++j) {
            if (numbers[j] > numbers[maxIndex]) {
                maxIndex = j;
            }
        }
        // Swap the maximum element with the current element
        swap(numbers[i], numbers[maxIndex]);

        // Print the array after each pass
        for (int k = 0; k < numElements; ++k) {
            cout << numbers[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int maxSize = 10;
    int numbers[maxSize];
    int numElements = 0;
    int input;

    // Read input until -1 is encountered or the array is full
    while (cin >> input && input != -1 && numElements < maxSize) {
        numbers[numElements++] = input;
    }

    // Call the selection sort function
    SelectionSortDescendTrace(numbers, numElements);

    return 0;
}
