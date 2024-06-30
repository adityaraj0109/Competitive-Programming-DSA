#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//approach 1 //Memory Exceeded
bool solution1(string s, string p, int i, int j, vector<vector<int>> &dp){
    if(i<0 && j<0) return true;
    if(i>=0 && j<0) return false;
    if(i<0 && j>=0){
        for (int k = 0; k <=j; k++)
        {
            if(p[k]!='*'){
                return false;
            }
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    //matching condition
    if(s[i]==p[j] || p[j]=='?'){
        return dp[i][j]=solution1(s,p,i-1,j-1,dp);
    }
    else if (p[j]=='*')
    {
        return dp[i][j]=(solution1(s,p,i-1,j,dp) || solution1(s,p,i,j-1,dp));
    }
    else{
        return false;
    }
}

//approach 2 //making it a 1 based indexing 
bool solution2(string s, string p){
    vector<vector<bool>>dp(s.size()+1,vector<bool>(p.size()+1,false));
    dp[0][0]=true;
    for (int j = 1; j <=p.size(); j++)
    {
        bool flag=true;
        for (int k = 1; k <=j; k++)
        {
            if(p[k-1]!='*'){
                flag=false;
                break;
            }
        }
        dp[0][j]=flag;
    }

    for (int i = 1; i <=s.size(); i++)
    {
        for (int j = 1; j <=p.size(); j++)
        {
            if(s[i-1]==p[j-1] || p[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }
            else if (p[j-1]=='*')
            {
                dp[i][j]=(dp[i-1][j] || dp[i][j-1]);
            }
            else{
                dp[i][j]=false;
            }
        }
    }
    return dp[s.size()][p.size()];
}

//approach 3
bool solution3(string s, string p){
    vector<bool>curr(p.size()+1,false);
    vector<bool>prev(p.size()+1,false);
    prev[0]=true;
    for (int j = 1; j <=p.size(); j++)
    {
        bool flag=true;
        for (int k = 1; k <=j; k++)
        {
            if(p[k-1]!='*'){
                flag=false;
                break;
            }
        }
        prev[j]=flag;
    }

    for (int i = 1; i <=s.size(); i++)
    {
        for (int j = 1; j <=p.size(); j++)
        {
            if(s[i-1]==p[j-1] || p[j-1]=='?'){
                curr[j]=prev[j-1];
            }
            else if (p[j-1]=='*')
            {
                curr[j]=(prev[j] || curr[j-1]);
            }
            else{
                curr[j]=false;
            }
        }
        prev=curr;
    }
    return prev[p.size()];
}

bool isMatch(string s, string p)
{
    //for approach 1
    // vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
    // return solution1(s,p,s.size()-1,p.size()-1,dp);

    //for approach 2
    // return solution2(s,p);

    //for approach 3
    return solution3(s,p);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
