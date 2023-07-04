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

// approach 1
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

// approach 2 //TLE
int solution1(string text1, string text2, int i, int j, vector<vector<int>> &dp)
{
    if (i == text1.size())
        return 0;
    if (j == text2.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if (text1[i] == text2[j])
    {
        ans = 1 + solution1(text1, text2, i + 1, j + 1, dp);
    }
    else
    {
        ans = max(solution1(text1, text2, i + 1, j, dp), solution1(text1, text2, i, j + 1, dp));
    }
    return dp[i][j] = ans;
}

// approach 3
int solution2(string text1, string text2)
{
    vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
    int n1 = text1.size();
    int n2 = text2.size();
    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = 1 + dp[i+1][j+1];
            }
            else
            {
                ans = max(dp[i+1][j], dp[i][j+1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

// approach 4
int solution3(string text1, string text2)
{
    int n1 = text1.size();
    int n2 = text2.size();
    vector<int>curr(n2+1,0);
    vector<int>next(n2+1,0);
    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = 1 + next[j+1];
            }
            else
            {
                ans = max(next[j], curr[j+1]);
            }
            curr[j] = ans;
        }
        next=curr;
    }
    return next[0];
}

int longestCommonSubsequence(string text1, string text2)
{
    // for approach 1
    //  int n1=text1.length()-1;
    //  int n2=text2.length()-1;
    //  memset(dp,-1,sizeof(dp));
    //  return lcs(text1,text2,n1,n2);

    // for approach 2
    // vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    // return solution1(text1, text2, 0, 0, dp);

    // for approach 3
    // return solution2(text1,text2);

    // for approach 4
    return solution3(text1,text2);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
