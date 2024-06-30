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

// solution 1
//  int lis(int n,vector<int> &nums, vector<int> &dp){
//      if(dp[n]!=-1) return dp[n];
//      int ans=1;
//      for (int i = 0; i < n; i++)
//      {
//          if (nums[n]>nums[i])
//          {
//              ans=max(ans,lis(i,nums,dp)+1);
//          }
//      }
//      return dp[n]=ans;
//  }

// int lengthOfLIS(vector<int> &nums)
// {
//     vector<int>dp(nums.size(),-1);
//     int ans=0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         ans=max(ans,lis(i,nums,dp));
//     }
//     return ans;
// }

// solution 2

// approach 1
int solution1(vector<int> &nums, int index, int prevIndex, vector<vector<int>> &dp)
{
    if (index == nums.size())
        return 0;
    if (dp[index][prevIndex + 1] != -1)
        return dp[index][prevIndex + 1];

    int ans = 0;
    if (prevIndex == -1 || nums[index] > nums[prevIndex])
    {
        ans = 1 + solution1(nums, index + 1, index, dp);
    }
    ans = max(ans, solution1(nums, index + 1, prevIndex, dp));
    return dp[index][prevIndex + 1] = ans;
}

// approach 2
int solution2(vector<int> &nums){
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
    for (int index = nums.size()-1; index>=0; index--)
    {
        for (int prevIndex = index-1; prevIndex >=-1; prevIndex--)
        {
            int ans=0;
            if (prevIndex == -1 || nums[index] > nums[prevIndex])
            {
                ans = 1 + dp[index + 1][index];
            }
            ans = max(ans, dp[index + 1][prevIndex+1]);
            dp[index][prevIndex + 1] = ans;
        }
    }
    return dp[0][0];
}

// approach 3
int solution3(vector<int> &nums){
    int n=nums.size();
    vector<int>curr(n+1,0);
    vector<int>next(n+1,0);
    for (int index = nums.size()-1; index>=0; index--)
    {
        for (int prevIndex = index-1; prevIndex >=-1; prevIndex--)
        {
            int ans=0;
            if (prevIndex == -1 || nums[index] > nums[prevIndex])
            {
                ans = 1 + next[index];
            }
            ans = max(ans, next[prevIndex+1]);
            curr[prevIndex + 1] = ans;
        }
    }
    return next[0];
}

int lengthOfLIS(vector<int> &nums)
{
    //for approach 1
    // vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
    // return solution1(nums, 0, -1, dp);

    //for approach 2
    // return solution2(nums);

    //for approach 3
    return solution3(nums);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
