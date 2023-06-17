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

int solution(int arr[], int index,vector<int> &dp){
    if(index==0) return arr[0];
    if(index<0) return 0;
    if(dp[index]!=-1) return dp[index];

    int ans=solution(arr,index-2,dp)+arr[index];
    ans=max(ans,solution(arr,index-1,dp));
    return dp[index]=ans;
}

int FindMaxSum(int arr[], int n)
{
    vector<int>dp(n,-1);
    return solution(arr,n-1,dp);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
