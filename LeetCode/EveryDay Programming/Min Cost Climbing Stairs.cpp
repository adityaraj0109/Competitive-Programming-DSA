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

int solution(int index, vector<int> &dp, vector<int> &cost)
{
    if(index<0) return 0;
    if(dp[index]!=-1) return dp[index];
    int ans=solution(index-1,dp,cost)+cost[index];
    ans=min(ans,solution(index-2,dp,cost)+cost[index]);
    return dp[index]=ans;
}

int minCostClimbingStairs(vector<int> &cost)
{
    cost.push_back(0);
    int n = cost.size()-1;
    vector<int> dp(n+1, -1);
    return solution(n, dp, cost);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
