/*Implement a problem of number of zeroes.
Statement: Given an array of 1s and 0s which has all 1s first 
followed by all 0s? Find the number of 0s. Count the number of 
zeroes in the given array.
Input: arr[] = {1, 1, 1, 1, 0, 0} Output: 2
Input: arr[] = {1, 0, 0, 0, 0} Output: 4
USE DIVIDE AND CONQUER TECHNIQUE*/

#include<iostream>
using namespace std;

int countZeroes(int arr[],int n)
{
    int low=0,high=n-1;
    while (low<=high)
    {
       int mid=(low+high)/2;

       if(arr[mid]==0&&(mid==0||arr[mid-1]==1))
       {
        return n-mid;
       }
       else if(arr[mid]==1)
       {
        low=mid+1;
       }
       else{
        high=mid-1;
       }
    }
    
    return 0;
}

int main()
{
    int n,arr[n];
    cout<<"Enter the size of array: ";
    cin>>n;

    cout << "Enter the elements of the array (only 1s followed by 0s): ";
    for (int i = 0; i < n; ++i) 
    {
    cin >> arr[i];
    }

    int result = countZeroes(arr, n);
    cout << "Number of zeroes in the array: " << result << endl;

    return 0;
}