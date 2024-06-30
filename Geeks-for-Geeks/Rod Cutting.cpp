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

int solution(int price[], int n, vector<int> &dp){
    if (n==0) return 0;
    if (dp[n]!=-1) return dp[n];
    int ans=0;
    for (int i=1;i<=n;i++){
        if(n-i>=0){
            ans=max(ans,solution(price,n-i,dp)+price[i-1]);
        }
    }
    return dp[n]=ans;
}

int cutRod(int price[], int n)
{
    vector<int>dp(n+1,-1);
    return solution(price,n,dp);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
