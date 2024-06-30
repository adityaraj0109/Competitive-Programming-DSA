#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int solution(string A,vector<int> &dp, int index,unordered_map<string,int> &m){
    if(index==A.size()) return 1;
    if(dp[index]!=-1) return dp[index];
    string str="";
    for (int i = index; i < A.size(); i++)
    {
        str+=A[i];
        if(m[str]){
            if(solution(A,dp,i+1,m)){
                return dp[index]=1;
            }
        }
    }
    return dp[index]=0;
}

int wordBreak(string A, vector<string> &B)
{
    unordered_map<string,int>m;
    for(auto it:B){
        m[it]=1;
    }
    if(m[A]) return 1;
    vector<int>dp(A.size(),-1);
    return solution(A,dp,0,m);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
