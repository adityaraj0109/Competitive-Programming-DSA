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
int solution1(vector<vector<int>> &mat,vector<vector<int>> &dp, int &ans,int i, int j){
    if(i>=mat.size() || j>=mat[0].size()){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    int right=solution1(mat,dp,ans,i,j+1);
    int diagonal=solution1(mat,dp,ans,i+1,j+1);
    int down=solution1(mat,dp,ans,i+1,j);

    if(mat[i][j]==1){
        dp[i][j]=1+min(right,min(diagonal,down));
        ans=max(ans,dp[i][j]);
        return dp[i][j];
    }
    else{
        return dp[i][j]=0;
    }
}

//approach 2
int solution2(int n, int m, vector<vector<int>> &mat){
    int ans=0;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i = n-1; i >=0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            int right=dp[i][j+1];
            int diagonal=dp[i+1][j+1];
            int down=dp[i+1][j];

            if(mat[i][j]==1){
                dp[i][j]=1+min(right,min(diagonal,down));
                ans=max(ans,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return ans;
}

//approach 3
int solution3(int n, int m, vector<vector<int>> &mat){
    int ans=0;
    vector<int>curr(m+1,0);
    vector<int>next(m+1,0);
    for (int i = n-1; i >=0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            int right=curr[j+1];
            int diagonal=next[j+1];
            int down=next[j];

            if(mat[i][j]==1){
                curr[j]=1+min(right,min(diagonal,down));
                ans=max(ans,curr[j]);
            }
            else{
                curr[j]=0;
            }
        }
        next=curr;
    }
    return ans;
}

int maxSquare(int n, int m, vector<vector<int>> mat)
{
    //for approach 1
    // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    // int ans=0;
    // int temp=solution1(mat,dp,ans,0,0);
    // return ans;

    //for approach 2
    // return solution2(n,m,mat);

    //for approach 3
    return solution3(n,m,mat);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
