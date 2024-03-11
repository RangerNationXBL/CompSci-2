// Implement the radix sort algorithm described in Review Exercise 12.15.22 to sort arrays of numbers between 0 and 999.

#include <iostream>
#include <vector>

// Function to perform counting sort based on a specific digit position
void countingSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    // Count the occurrences of each digit
    for (int i = 0; i < n; ++i) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Function to perform radix sort
void radixSort(std::vector<int>& arr) {
    int maxNum = *std::max_element(arr.begin(), arr.end());

    // Perform counting sort for each digit position
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
