#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool solution(string wild, string pattern, int i, int j, vector<vector<int>> &dp){
    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;
    if(j<0 && i>=0){
        while (i>=0)
        {
            if(wild[i]!='*'){
                return false;
            }
            i--;
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(wild[i]==pattern[j] || wild[i]=='?'){
        return dp[i][j]=solution(wild,pattern,i-1,j-1,dp);
    }
    else if(wild[i]=='*'){
        return dp[i][j]=solution(wild,pattern,i-1,j,dp)||solution(wild,pattern,i,j-1,dp);
    }
    else{
        return false;
    }
}

bool match(string wild, string pattern)
{
    int n=wild.size();
    int m=pattern.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solution(wild,pattern,n-1,m-1,dp);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
