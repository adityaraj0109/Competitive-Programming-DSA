#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int maxHeight(vector<vector<int>> &cuboids)
{
    for(auto &it:cuboids){
        sort(it.begin(),it.end());
    }
    sort(cuboids.begin(),cuboids.end());
    int n=cuboids.size();
    vector<int>dp(n+1,0);
    dp[0]=cuboids[0][2];
    for(int i=1;i<n;i++){
        int flag=0;
        for(int j=0;j<i;j++){
            if(cuboids[i][0]>=cuboids[j][0] && cuboids[i][1]>=cuboids[j][1] && cuboids[i][2]>=cuboids[j][2]){
                dp[i]=max(dp[i],dp[j]+cuboids[i][2]);
                flag=1;
            }
        }
        if(!flag) dp[i]=cuboids[i][2];
    }
    return *max_element(dp.begin(),dp.end());
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
