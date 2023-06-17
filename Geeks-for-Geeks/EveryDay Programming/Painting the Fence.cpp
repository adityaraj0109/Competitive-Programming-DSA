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

int m = 1e9 + 7;

int add(int a,int b){
    return (a%m+b%m)%m;
}

int mul(int a,int b){
    return ((a%m)*1LL*(b%m))%m;
}

long long solution(int n, int k,vector<int> &dp){
    if(n==1) return k;
    if(n==2) return add(k,mul(k,k-1));
    if(dp[n]!=-1) return dp[n];

    long long ans=add(mul(solution(n-2,k,dp),k-1),mul(solution(n-1,k,dp),k-1));
    return dp[n]=ans;
}

long long countWays(int n, int k)
{
    vector<int>dp(n+1,-1);
    return solution(n,k,dp);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
