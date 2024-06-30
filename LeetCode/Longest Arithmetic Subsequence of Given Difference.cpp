#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int longestSubsequence(vector<int> &arr, int difference)
{
    int ans=0;
    unordered_map<int,int>dp;
    for (int i = 0; i < arr.size(); i++)
    {
        int temp=arr[i]-difference;
        int count=0;
        if(dp[temp]) count=dp[temp];
        dp[arr[i]]=1+count;
        ans=max(ans,dp[arr[i]]); 
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
