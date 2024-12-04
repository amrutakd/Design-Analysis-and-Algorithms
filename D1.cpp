/*Implement program to find all distinct subsets of a given set 
using Bit Masking Approach.
Statement Given an array of integers arr[], The task is to find all 
its subsets. The subset cannot contain duplicate elements, so any
repeated subset should be considered only once in the output.
Input: S = {1, 2, 2} Output: {}, {1}, {2}, {1, 2}, {2, 2}, {1, 2,2}
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void findSubsets(vector<int>& arr) {
    int n = arr.size();
    set<vector<int>> uniqueSubsets;

    // Total number of subsets is 2^n
    int totalSubsets = 1 << n; 

    for (int mask = 0; mask < totalSubsets; mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            // Check if the ith bit is set in the current mask
            if (mask & (1 << i)) {
                subset.push_back(arr[i]);
            }
        }
        // Sort subset to handle duplicates effectively
        sort(subset.begin(), subset.end());
        uniqueSubsets.insert(subset);
    }

    // Print all unique subsets
    for (const auto& subset : uniqueSubsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 2};
    findSubsets(arr);
    return 0;
}
