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

int lis(int n,vector<int> &nums, vector<int> &dp){
    if(dp[n]!=-1) return dp[n];
    int ans=1;
    for (int i = 0; i < n; i++)
    {
        if (nums[n]>nums[i])
        {
            ans=max(ans,lis(i,nums,dp)+1);
        }
    }
    return dp[n]=ans;
}

int lengthOfLIS(vector<int> &nums)
{
    vector<int>dp(nums.size(),-1);
    int ans=0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans=max(ans,lis(i,nums,dp));
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
