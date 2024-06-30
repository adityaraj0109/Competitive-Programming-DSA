#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//approach 1
int solution1(string word1, string word2,int i, int j, vector<vector<int>> &dp){
    if(i==word1.size()) return word2.size()-j;
    if(j==word2.size()) return word1.size()-i;
    if(dp[i][j]!=-1) return dp[i][j];
 
    int ans=0;
    if(word1[i]==word2[j]){
        return solution1(word1,word2,i+1,j+1,dp);
    }
    else{
        //insert operation
        int ans1=1+solution1(word1,word2,i,j+1,dp);
        //delete operation
        int ans2=1+solution1(word1,word2,i+1,j,dp);
        //replace operation
        int ans3=1+solution1(word1,word2,i+1,j+1,dp);
        ans=min(ans1,min(ans2,ans3));
    }
    return dp[i][j]=ans;
}

//approach 2
int solution2(string word1, string word2){
    vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
    for (int j = 0; j < word2.size(); j++)
    {
        dp[word1.size()][j]=word2.size()-j;
    }
    for (int i = 0; i < word1.size(); i++)
    {
        dp[i][word2.size()]=word1.size()-i;
    }
    for (int i = word1.size()-1; i >=0; i--)
    {
        for (int j = word2.size()-1; j >=0; j--)
        {
            int ans=0;
            if(word1[i]==word2[j]){
                ans=dp[i+1][j+1];
            }
            else{
                //insert operation
                int ans1=1+dp[i][j+1];
                //delete operation
                int ans2=1+dp[i+1][j];
                //replace operation
                int ans3=1+dp[i+1][j+1];
                ans=min(ans1,min(ans2,ans3));
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][0];
}

int minDistance(string word1, string word2)
{
    //for approach 1
    // vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
    // return solution1(word1,word2,0,0,dp);

    //for approach 2
    return solution2(word1,word2);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
