#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int solution(vector<int> &arr, int start, int end,vector<vector<int>> &dp,map<pair<int,int>,int> &m){
    if(start>=end) return 0;
    if(dp[start][end]!=-1) return dp[start][end];
    int ans=INT_MAX;
    for (int i = start; i <end; i++)
    {
        ans=min(ans,m[{start,i}]*m[{i+1,end}]+solution(arr,start,i,dp,m)+solution(arr,i+1,end,dp,m));
    }
    return dp[start][end]=ans;
}

int mctFromLeafValues(vector<int> &arr)
{
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    map<pair<int,int>,int>m;
    for (int i = 0; i < n; i++)
    {
        m[{i,i}]=arr[i];
        for (int j = i+1; j <n; j++)
        {
            m[{i,j}]=max(arr[j],m[{i,j-1}]);
        }
    }
    return solution(arr,0,n-1,dp,m);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
