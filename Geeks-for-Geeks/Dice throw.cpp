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
long long solution1(int dice, int face, int target,vector<vector<long long>> &dp){
    if(target==0 && dice==0) return 1;
    if(target<=0) return 0;
    if(target==0 && dice!=0) return 0;
    if(target!=0 && dice==0) return 0;
    if(dp[dice][target]!=-1) return dp[dice][target];

    long long ans=0;
    for (int i = 1; i <= face; i++)
    {
        ans+=solution1(dice-1,face,target-i,dp);
    }
    return dp[dice][target]=ans;
}

//approach 2
long long solution2(int d, int f, int t){
    vector<vector<long long>>dp(d+1,vector<long long>(t+1,0));
    dp[0][0]=1; //base condition
    for (int dice = 1; dice <=d; dice++)
    {
        for (int target = 1; target <=t; target++)
        {
            long long ans=0;
            for (int i = 1; i <= f; i++)
            {
                if(target-i>=0){
                    ans+=dp[dice-1][target-i];
                }
            }
            dp[dice][target]=ans;
        }
    }
    return dp[d][t];
}

//approach 3
long long solution3(int d, int f, int t){
    vector<long long>prev(t+1,0);
    vector<long long>curr(t+1,0);
    prev[0]=1; //base condition
    for (int dice = 1; dice <=d; dice++)
    {
        for (int target = 1; target <=t; target++)
        {
            long long ans=0;
            for (int i = 1; i <= f; i++)
            {
                if(target-i>=0){
                    ans+=prev[target-i];
                }
            }
            curr[target]=ans;
        }
        prev=curr;
    }
    return prev[t];
}

long long noOfWays(int M, int N, int X)
{
    //for approach 1
    // vector<vector<long long>>dp(N+1,vector<long long>(X+1,-1));
    // return solution1(N,M,X,dp);

    //for approach 2
    // return solution2(N,M,X);
    
    //for approach 3
    return solution3(N,M,X);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
