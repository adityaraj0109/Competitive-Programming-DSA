#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//approach 1
int solution1(int start, int end, vector<vector<int>> &dp){
    if(start>=end){
        return 0;
    }
    if(dp[start][end]!=-1) return dp[start][end];

    int ans=INT_MAX;
    for (int i = start; i <=end; i++)
    {
        ans=min(ans,i+max(solution1(start,i-1,dp),solution1(i+1,end,dp)));
    }
    return dp[start][end]=ans;
}

//approach 2
int solution2(int n){
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    for (int start = n; start >=1; start--)
    {
        for (int end = start; end <=n; end++)
        {
            if(start==end) continue;
            else{
                int ans=INT_MAX;
                for (int i = start; i <=end; i++)
                {
                    ans=min(ans,i+max(dp[start][i-1],dp[i+1][end]));
                }
                dp[start][end]=ans;
            }
        }
    }
    return dp[1][n];
}

int getMoneyAmount(int n)
{
    //for approach 1
    // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    // return solution1(1,n,dp);

    //for approach 2
    return solution2(n);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
