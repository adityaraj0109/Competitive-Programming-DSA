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

int solution(int W, int wt[], int val[], int index, vector<vector<int>> &dp){
    if(W==0) return 0;
    if(index<0) return 0;
    if(dp[index][W]!=-1) return dp[index][W];

    int ans=solution(W,wt,val,index-1,dp);
    if (W-wt[index]>=0)
    {
        ans=max(ans,solution(W-wt[index],wt,val,index-1,dp)+val[index]);
    }
    return dp[index][W]=ans;
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    return solution(W,wt,val,n-1,dp);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
