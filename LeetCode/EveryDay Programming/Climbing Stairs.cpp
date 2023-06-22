#include <bits/stdc++.h>
#define ll long long
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int solution(int n, vector<int> &dp){
    if (n==0) return 1;
    if (n<0) return 0;
    if (dp[n]!=-1) return dp[n];
    int ans = 0;
    ans+=solution(n-1,dp);
    ans+=solution(n-2,dp);
    return dp[n] = ans;
}

int climbStairs(int n)
{
    vector<int>dp(n+1,-1);
    return solution(n,dp);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
