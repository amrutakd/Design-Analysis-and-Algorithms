#include <iostream>
using namespace std;

void generateSubsets(int arr[], int n, int index, int subset[], int subsetSize) {
    // Base case: If we've considered all elements, print the subset
    if (index == n) {
        cout << "{ ";
        for (int i = 0; i < subsetSize; ++i) {
            cout << subset[i] << " ";
        }
        cout << "}" << endl;
        return;
    }

    // Exclude the current element and move to the next
    generateSubsets(arr, n, index + 1, subset, subsetSize);

    // Include the current element in the subset
    subset[subsetSize] = arr[index];
    generateSubsets(arr, n, index + 1, subset, subsetSize + 1);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int subset[n]; // Array to store elements of the current subset

    generateSubsets(arr, n, 0, subset, 0);
    return 0;
}
