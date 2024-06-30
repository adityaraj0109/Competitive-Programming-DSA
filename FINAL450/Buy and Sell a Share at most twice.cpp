#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int solution(vector<int>&price,int index, int k, int buy,vector<vector<vector<int>>> &dp){
    if(index==price.size()) return 0;
    if(k==2) return 0;
    if(dp[index][k][buy]!=-1) return dp[index][k][buy];
    if (!buy)
    {
        int take=-price[index]+solution(price,index+1,k,1,dp);
        int notTake=0+solution(price,index+1,k,0,dp);
        dp[index][k][buy]=max(take,notTake);
    }
    else{
        int take=price[index]+solution(price,index+1,k+1,0,dp);
        int notTake=0+solution(price,index+1,k,1,dp);
        dp[index][k][buy]=max(take,notTake);
    }
    return dp[index][k][buy];
}

int maxProfit(vector<int>&price){
    int n=price.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return solution(price,0,0,0,dp);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
