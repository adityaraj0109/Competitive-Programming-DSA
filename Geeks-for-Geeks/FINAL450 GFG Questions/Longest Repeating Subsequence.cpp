#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//This solution is giving TLE
int solution1(string str, int i, int j,vector<vector<int>> &dp){
    if(i==str.size() || j==str.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(str[i]==str[j] && i!=j){
        ans=1+solution1(str,i+1,j+1,dp);
    }
    else{
        ans=max(solution1(str,i+1,j,dp),solution1(str,i,j+1,dp));
    }
    return dp[i][j]=ans;
}

//approach 2
int solution2(string str){
    int n=str.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for (int i = n-1; i >=0; i--)
    {
        for (int j = n-1; j >=0; j--)
        {
            int ans=0;
            if(str[i]==str[j] && i!=j){
                ans=1+dp[i+1][j+1];
            }
            else{
                ans=max(dp[i+1][j],dp[i][j+1]);
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][0];
}

int LongestRepeatingSubsequence(string str)
{
    //for approach 1
    // int n=str.size();
    // vector<vector<int>>dp(n,vector<int>(n,-1));
    // return solution1(str,0,0,dp);

    //for approach 2
    return solution2(str);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
