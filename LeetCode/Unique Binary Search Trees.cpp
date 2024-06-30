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
int solution1(int n,vector<int> &dp){
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for (int i = 1; i <=n; i++)
    {
        ans+=solution1(i-1,dp)*solution1(n-i,dp);
    }
    return dp[n]=ans;
}

//approach 2
int solution2(int n){
    vector<int>dp(n+1,0);
    dp[0]=dp[1]=1;
    //in this approach i is working as n and j is working as i
    for (int i = 2; i <=n; i++)
    {
        int ans=0;
        for (int j = 1; j <=i; j++)
        {
            ans+=dp[j-1]*dp[i-j];
        }
        dp[i]=ans;
    }
    return dp[n];
}

int numTrees(int n)
{
    //for approach 1
    vector<int>dp(n+1,-1);
    return solution1(n,dp);

    //for approach 2
    // return solution2(n);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
