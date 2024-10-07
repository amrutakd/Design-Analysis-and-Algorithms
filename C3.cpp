/*Implement Check if it is possible to transform one string to 
another.
Statement Given two strings s1 and s2 (all letters in uppercase). 
Check if it is possible to convert s1 to s2 by performing following 
operations.
1. Make some lowercase letters uppercase.
2. Delete all the lowercase letters.
Input: s1 = daBcd s2 = ABC Output: yes*/

#include<iostream>
using namespace std;

//function to check if a string can be converted to another string
bool check(string s1,string s2)
{
    //calculate length of both string
    int n=s1.length();
    int m=s2.length();
    
    bool dp[n + 1][m + 1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j] = false;
        }
    }

    //mark 1st position as true 
    dp[0][0] = true;

    //traverse for all DP[i][j]
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            //if possible to convert i character of s1 to j character of s2
            if(dp[i][j])
            {
                //if upper case(s1[i]==s2[j])is same
                if(j<s2.length() && (toupper(s2[i]==s2[j])))
                dp[i+1][j+1] = true;

                //if not upper the deletion is possible 
                if(!isupper(s1[i]))
                dp[i+1][j] = true;
            }
        }
    }

    return (dp[n][m]);
}

//driver code
int main()
{
    string s1 = "daBcd";
    string s2 = "ABC";

    if(check(s1,s2))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;

    return 0;
}
