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

int dp[310][5010];

int solution(int amount, vector<int> &coins, int index){
    if(amount==0) return 1;
    if(index<0) return 0;
    if(dp[index][amount]!=-1) return dp[index][amount];

    int ways=0;
    for (int coin_amount = 0; coin_amount <=amount; coin_amount+=coins[index])
    {
        if (amount-coin_amount>=0)
        {
            ways+=solution(amount-coin_amount,coins,index-1);
        }
    }
    return dp[index][amount]=ways;
}

int change(int amount, vector<int> &coins)
{
    memset(dp,-1,sizeof(dp));
    int index=coins.size();
    return solution(amount,coins,index);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
