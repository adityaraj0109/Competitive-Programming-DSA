#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int solution(string s, string t, int i, int j, vector<vector<int>> &dp){
    if(j==t.size()) return 1;
    if(i==s.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(s[i]==t[j]){
        ans=solution(s,t,i+1,j+1,dp)+solution(s,t,i+1,j,dp);
    }
    else{
        ans=solution(s,t,i+1,j,dp);
    }
    return dp[i][j]=ans;
}

int numDistinct(string s, string t)
{
    vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
    return solution(s,t,0,0,dp);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
