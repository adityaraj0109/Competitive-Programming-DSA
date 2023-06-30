#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int solution(vector<int> &A, int target, int index, vector<vector<int>>&dp, int n){
    if(target==0) return 1;
    if(index>=n) return 0;
    if(dp[index][target]!=-1) return dp[index][target];
    int ans=solution(A,target,index+1,dp,n);
    if(target-A[index]>=0){
        ans|=solution(A,target-A[index],index+1,dp,n);
    }
    return dp[index][target]=ans;
}

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    vector<vector<int>>dp(n,vector<int>(B+1,-1));
    return solution(A,B,0,dp,n);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
