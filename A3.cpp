/*Implement a problem of smallest number with at least n 
trailing zeroes in factorial.
Statement: Given a number n. The task is to find the smallest 
number whose factorial contains at least n trailing zeroes.
USE DIVIDE AND CONQUER TECHNIQUE*/

#include<iostream>
using namespace std;

int countTrailingZero(int num)
{
 int count=0;
 while (num>=5)
 {
    num/=5;
    count+=num;

 }
 return count;
}

int findMinFact(int n)
{
    if(n==0)
    return 0;

    int high,low,mid;
    
    low=0;
    high=5*n;

    while (low<high)
    {
        mid=(low+high)/2;

        if(countTrailingZero(mid)<n)
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    return low;
}

int main()
{
    int n,result;
    cout<<"Enter Number of Trailing Zeroes Required : ";
    cin>>n;

    result=findMinFact(n);
    cout<<"The Smallest number whose factorial has at least  "<<n<<"  trailing zeroes is "<<result<<endl;
   
   return 0;
}