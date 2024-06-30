#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int mod=1e9+7;
//approach 1 is giving TLE
long long int solution1(string str, int i, int j,vector<vector<int>> &dp){
    if(i==j) return 1;
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    long long int ans;
    if(str[i]==str[j]){
        ans=(1+solution1(str,i+1,j,dp)+solution1(str,i,j-1,dp))%mod;
    }
    else{
        ans=(solution1(str,i+1,j,dp)+solution1(str,i,j-1,dp)-solution1(str,i+1,j-1,dp))%mod;
    }
    return dp[i][j]=ans;
}

//approach 2
long long int solution2(string str){
    int n=str.length();
    vector<vector<long long int>>dp(n+1,vector<long long int>(n+1,0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i]=1;
    }
    for (int i = n-2; i >=0; i--)
    {
        for (int j = i+1; j < n; j++)
        {
            long long int ans;
            if(str[i]==str[j]){
                ans=1+dp[i+1][j]+dp[i][j-1];
            }
            else{
                ans=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            }
            ans+=mod;
            ans=ans%mod;
            dp[i][j]=ans;
        }
    }
    return dp[0][n-1];
}

long long int countPS(string str)
{
    //for approach 1
    // int n=str.length();
    // vector<vector<long long int>>dp(n,vector<long long int>(n,-1));
    // return solution(str,0,n-1,dp);

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
