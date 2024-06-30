#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool solution1(string &s, string &p,int i, int j, vector<vector<int>>&dp){
    if(i<0 && j<0) return true;
    if(i>=0 && j<0) return false;
    if(i<0 && j>=0){
        if(p[j]=='*') return solution1(s,p,i,j-2,dp);
        else return false;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==p[j] || p[j]=='.') return dp[i][j]=solution1(s,p,i-1,j-1,dp);
    else if(p[j]=='*'){
        bool temp=false;
        if(s[i]==p[j-1] || p[j-1]=='.') temp=temp || solution1(s,p,i-1,j,dp);
        return dp[i][j]=temp || solution1(s,p,i,j-2,dp);
    }
    else return false;
}

bool isMatch(string s, string p) {
    vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
    return solution1(s,p,s.size()-1,p.size()-1,dp);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
