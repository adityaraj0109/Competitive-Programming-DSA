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
int solution1(vector<int> &prices,vector<vector<vector<int>>> &dp, int index, int buy, int limit){
    if(index>=prices.size()) return 0;
    if(limit==0) return 0;
    if(dp[index][buy][limit]!=-1) return dp[index][buy][limit];
    if(buy){
        int take=-prices[index]+solution1(prices,dp,index+1,0,limit);
        int notTake=0+solution1(prices,dp,index+1,1,limit);
        dp[index][buy][limit]=max(take,notTake);
    }
    else{
        int take=prices[index]+solution1(prices,dp,index+1,1,limit-1);
        int notTake=0+solution1(prices,dp,index+1,0,limit);
        dp[index][buy][limit]=max(take,notTake);
    }
    return dp[index][buy][limit];
}

//approach 2
int solution2(vector<int> &prices){
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for (int index = n-1; index >=0; index--)
    {
        for (int buy = 0; buy <=1; buy++)
        {
            for (int limit = 1; limit <=2; limit++)
            {
                if(buy){
                int take=-prices[index]+dp[index+1][0][limit];
                int notTake=0+dp[index+1][1][limit];
                dp[index][buy][limit]=max(take,notTake);
                }
                else{
                    int take=prices[index]+dp[index+1][1][limit-1];
                    int notTake=0+dp[index+1][0][limit];
                    dp[index][buy][limit]=max(take,notTake);
                }
            }
        }
    }
    return dp[0][1][2];
}

//approach 3
int solution3(vector<int> &prices){
    int n=prices.size();
    vector<vector<int>>curr(2,vector<int>(3,0));
    vector<vector<int>>next(2,vector<int>(3,0));
    for (int index = n-1; index >=0; index--)
    {
        for (int buy = 0; buy <=1; buy++)
        {
            for (int limit = 1; limit <=2; limit++)
            {
                if(buy){
                int take=-prices[index]+next[0][limit];
                int notTake=0+next[1][limit];
                curr[buy][limit]=max(take,notTake);
                }
                else{
                    int take=prices[index]+next[1][limit-1];
                    int notTake=0+next[0][limit];
                    curr[buy][limit]=max(take,notTake);
                }
            }
        }
        next=curr;
    }
    return next[1][2];
}

int maxProfit(vector<int> &prices)
{
    //for approach 1
    // int n=prices.size();
    // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    // return solution1(prices,dp,0,1,2);

    //for approach 2
    // return solution2(prices);

    //for approach 3
    return solution3(prices);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
