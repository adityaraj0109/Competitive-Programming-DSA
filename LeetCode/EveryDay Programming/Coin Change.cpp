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

int solution(vector<int> &dp,vector<int> &coins, int amount){
    int ans=1e9;
    if (amount==0)
    {
        return 0;
    }
    if (dp[amount]!=-1)
    {
        return dp[amount];
    }
    for(auto coin:coins){
        if (amount-coin>=0)
        {
            ans=min(ans,solution(dp,coins,amount-coin)+1);
        }
    }
    return dp[amount]=ans;
}

int coinChange(vector<int> &coins, int amount)
{
    vector<int>dp(amount+1,-1);
    int ans=solution(dp,coins,amount);
    if (ans!=1e9)
    {
        return ans;
    }
    return -1;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
