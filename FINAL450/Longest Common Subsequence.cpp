#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//This approach is giving TLE
int solution1(string s1, string s2,vector<vector<int>> &dp, int i, int j){
    if(i==s1.size() || j==s2.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return dp[i][j]=1+solution1(s1,s2,dp,i+1,j+1);
    return dp[i][j]=max(solution1(s1,s2,dp,i+1,j),solution1(s1,s2,dp,i,j+1));
}

//approach 2
int solution2(int n, int m,string s1, string s2){
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i = n-1; i >=0; i--)
    {
        for (int j = m-1; j >=0; j--)
        {
            if(s1[i]==s2[j]) dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    return dp[0][0];
}

int lcs(int n, int m, string s1, string s2)
{
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // return solution1(s1,s2,dp,0,0);

    return solution2(n,m,s1,s2);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
