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

//approach 1
int solution1(vector<int> &days, vector<int> &costs, vector<int> &dp, int index,int n){
    if(index>=n) return 0;
    if(dp[index]!=-1) return dp[index];

    int ans=costs[0]+solution1(days,costs,dp,index+1,n);

    int i;
    for (i = index; i<n && days[i] < days[index]+7; i++);
    ans=min(ans,solution1(days,costs,dp,i,n)+costs[1]);

    for (i = index; i<n && days[i] < days[index]+30; i++);
    ans=min(ans,solution1(days,costs,dp,i,n)+costs[2]);

    return dp[index]=ans;
}

//approach 2
int solution2(vector<int> &days, vector<int> &costs){
    int n=days.size();
    vector<int>dp(n+1,INT_MAX);
    dp[n]=0;

    for (int index = n-1; index >= 0; index--)
    {
        int ans=costs[0]+dp[index+1];

        int i;
        for(i=index;i<n && days[i]<days[index]; i++);
        ans=min(ans,costs[1]+dp[i]);

        for(i=index;i<n && days[i]<days[index]; i++);
        ans=min(ans,costs[2]+dp[i]);
        dp[index]=ans;
    }

    return dp[0];
}

int solution3(vector<int> &days, vector<int> &costs){
    int ans=0;
    queue<pair<int,int>>month;
    queue<pair<int,int>>week;

    for(int day:days){
        while (!month.empty() && month.front().first+30<=day)
        {
            month.pop();
        }

        while (!week.empty() && week.front().first+7<=day)
        {
            week.pop();
        }
        
        week.push({day,ans+costs[1]});
        month.push({day,ans+costs[2]});

        ans=min(ans+costs[0],min(week.front().second,month.front().second));
    }
    return ans;
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    //for approach 1
    // int n=days.size();
    // vector<int>dp(n+1,-1);
    // return solution1(days,costs,dp,0,n);

    //for approach 2
    // return solution2(days,costs);

    //for approach 3
    return solution3(days,costs);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
