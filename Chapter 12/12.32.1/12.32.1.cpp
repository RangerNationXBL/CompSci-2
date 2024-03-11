#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recursions = 0;
int comparisons = 0;

vector<int> ReadIntegers() {
    int size;
    cin >> size;
    vector<int> integers(size);
    for (int i = 0; i < size; ++i) {
        cin >> integers[i];
    }
    sort(integers.begin(), integers.end());
    return integers;
}

int BinarySearch(int target, vector<int> &integers, int lower, int upper) {
    recursions++;
    if (lower <= upper) {
        int mid = lower + (upper - lower) / 2;
        if (integers[mid] == target) {
            comparisons++;
            return mid;
        } else if (integers[mid] < target) {
            comparisons += 2; // Increment comparison count for both comparisons below
            return BinarySearch(target, integers, mid + 1, upper);
        } else {
            comparisons += 2; // Increment comparison count for both comparisons below
            return BinarySearch(target, integers, lower, mid - 1);
        }
    }
    return -1;
}

int main() {
    int target;
    int index;

    vector<int> integers = ReadIntegers();

    cin >> target;

    index = BinarySearch(target, integers, 0, integers.size() - 1);
    if (index != -1) {
        comparisons++; // Increment comparison count for the final comparison
    }
    printf("index: %d, recursions: %d, comparisons: %d\n",
           index, recursions, comparisons);

    return 0;
}
