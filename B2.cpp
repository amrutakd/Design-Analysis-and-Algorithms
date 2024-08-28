/*Implement a problem of maximize Profit by trading stocks 
based on given rate per day.
Statement: Given an array arr[] of N positive integers which 
denotes the cost of selling and buying a stock on each of 
the N days. The task is to find the maximum profit that can be 
earned by buying a stock on or selling all previously bought stocks 
on a particular day.
Input: arr[] = {2, 3, 5} Output: 5
Solved using Greedy strategy*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shop {
    int start, end;
};

// Function to find the maximum number of shops that can be visited by K persons
int maxShopsVisited(vector<int>& S, vector<int>& E, int K) {
    int N = S.size();
    vector<Shop> shops(N);

    // Store the start and end times in the Shop structure
    for (int i = 0; i < N; ++i) {
        shops[i] = {S[i], E[i]};
    }

    // Sort the shops based on their end times
    sort(shops.begin(), shops.end(), [](Shop a, Shop b) {
        return a.end < b.end;
    });

    vector<int> persons(K, 0);
    int count = 0;

    // Assign shops to persons optimally
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (persons[j] <= shops[i].start) {
                persons[j] = shops[i].end;
                count++;
                break;
            }
        }
    }

    return count;
}

int main() {
    vector<int> S1 = {1, 8, 3, 2, 6};
    vector<int> E1 = {5, 10, 6, 5, 9};
    int K1 = 2;
    cout << "Maximum shops visited: " << maxShopsVisited(S1, E1, K1) << endl;

    vector<int> S2 = {1, 2, 3};
    vector<int> E2 = {3, 4, 5};
    int K2 = 2;
    cout << "Maximum shops visited: " << maxShopsVisited(S2, E2, K2) << endl;

     return 0;
}
