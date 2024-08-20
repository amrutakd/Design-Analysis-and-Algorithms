/*Implement a problem of move all zeroes to end of array.
Statement: Given an array of random numbers, Push all the zero’s 
of a given array to the end of the array. For example, if the given 
arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 
9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be 
same.
USE DIVIDE AND CONQUER TECHNIQUE*/

#include<iostream>
using namespace std;

int main()
{
    int i, a[10], temp[10], k = 0, n;
    cout << "enter array size" << endl;
    cin >> n;

    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;

    cout << "enter array elements" << endl;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(i = 0; i <= mid; i++)
    {
        if(a[i] != 0)
        {
            temp[k] = a[i];
            k++;
        }
    }
    
    for(i = mid + 1; i < n; i++)
    {
        if(a[i] != 0)
        {
            temp[k] = a[i];
            k++;
        }
    }
    
    while(k < n)
    {
        temp[k++] = 0;
    }

    for(k = 0; k < n; k++)
    {
        cout << temp[k] << " "; // 
    }
    
    return 0;
}