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
// int maxProfit(vector<int> &prices)
// {
//     int n=prices.size();
//     vector<int>maximum(n+1,0);
//     int ans=INT_MIN;
//     for (int i = n-1; i>=0; i--)
//     {
//         maximum[i]=max(maximum[i+1],prices[i]);
//     }
//     for (int i = 0; i<n; i++){
//         ans=max(ans,(prices[i]-maximum[i]));
//     }
//     if(ans<0) return 0;
//     return ans;
// }

//approach 2
int maxProfit(vector<int> &prices)
{
    int n=prices.size();
    int mini=prices[0];
    int profit=0;
    for (int i = 1; i < n; i++)
    {
        int diff=prices[i]-mini;
        profit=max(profit,diff);
        mini=min(mini,prices[i]);
    }
    return profit;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
