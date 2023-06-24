#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// approach 1
int solution1(vector<int> &satisfaction,vector<vector<int>> &dp, int index,int time){
    if(index==satisfaction.size()){
        return 0;
    }
    if(dp[index][time]!=-1) return dp[index][time];
    int ans=satisfaction[index]*time+solution1(satisfaction,dp,index+1,time+1);
    ans=max(ans,0+solution1(satisfaction,dp,index+1,time));
    return dp[index][time]=ans;
}

// approach 2
int solution2(vector<int> &satisfaction){
    int n=satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));  

    for(int index=n-1;index>=0;index--){
        for (int time = index; time >=0; time--)
        {
            int ans=satisfaction[index]*(time+1)+dp[index+1][time+1];
            ans=max(ans,dp[index+1][time]);
            dp[index][time]=ans;
        }
    }
    return dp[0][0];
}

// approach 3
int solution3(vector<int> &satisfaction){
    int n=satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    vector<int>curr(n+1,0);
    vector<int>next(n+1,0);

    for(int index=n-1;index>=0;index--){
        for (int time = index; time >=0; time--)
        {
            int ans=satisfaction[index]*(time+1)+next[time+1];
            ans=max(ans,next[time]);
            curr[time]=ans;
        }
        next=curr;
    }
    return next[0];
}

int maxSatisfaction(vector<int> &satisfaction)
{
    //for approach 1
    // int n=satisfaction.size();
    // sort(satisfaction.begin(),satisfaction.end());
    // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    // return solution1(satisfaction,dp,0,1);

    //for approach 2
    // return solution2(satisfaction);

    //for approach 3
    return solution3(satisfaction);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
