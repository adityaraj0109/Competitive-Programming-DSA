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
    if(i==s.size()) return t.size()-j;
    if(j==t.size()) return s.size()-i;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(s[i]==t[j]) ans=solution(s,t,i+1,j+1,dp);
    else{
        int insert=1+solution(s,t,i,j+1,dp);
        int remove=1+solution(s,t,i+1,j,dp);
        int replace=1+solution(s,t,i+1,j+1,dp);
        ans=min(insert,min(remove,replace));
    }
    return dp[i][j]=ans;
}

int editDistance(string s, string t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solution(s,t,0,0,dp);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
