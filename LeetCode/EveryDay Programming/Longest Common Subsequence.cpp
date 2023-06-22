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

int dp[1005][1005];

int lcs(string &text1, string &text2,int i, int j){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    //case1 where the last ch of text1 doesn't match with text2
    int ans=lcs(text1,text2,i-1,j);
    //case2 where the last ch of text2 doesn't match with text1
    ans=max(ans,lcs(text1,text2,i,j-1));
    //case3 where the last ch of text1 matches with text2 then add 1 or 0
    ans=max(ans,lcs(text1,text2,i-1,j-1)+(text1[i]==text2[j]));
    return dp[i][j]=ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    int n1=text1.length()-1;
    int n2=text2.length()-1;
    memset(dp,-1,sizeof(dp));
    return lcs(text1,text2,n1,n2);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
