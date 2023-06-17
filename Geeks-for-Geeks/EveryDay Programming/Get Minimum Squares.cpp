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

int solution(vector<int> &dp,int n){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    
    int ans=1e9;
    for (int i = 1; i*i <= n; i++)
    {
        if(n-i*i>=0){
            ans=min(ans,solution(dp,n-i*i)+1);
        }
    }
    return dp[n]=ans;
}

int MinSquares(int n)
{
    vector<int>dp(n+1,-1);
    return solution(dp,n);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
