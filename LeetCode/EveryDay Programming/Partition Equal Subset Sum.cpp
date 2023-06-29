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

// int dp[205][20005];

// bool solution(int index, int sum, vector<int> &nums)
// {
//     if (sum == 0)
//         return true;
//     if (index < 0)
//         return false;
//     if (dp[index][sum] != -1)
//         return dp[index][sum];

//     bool ans = solution(index - 1, sum, nums);
//     if (sum - nums[index] >= 0)
//     {
//         ans |= solution(index - 1, sum - nums[index], nums);
//     }
//     return dp[index][sum] = ans;
// }

// bool canPartition(vector<int> &nums)
// {
//     memset(dp, -1, sizeof(dp));
//     int n = nums.size() - 1;
//     int sum = accumulate(nums.begin(), nums.end(), 0);
//     if (sum % 2 != 0)
//         return false;
//     sum = sum / 2;
//     return solution(n, sum, nums);
// }

//approach 2
bool solution1(vector<int> &nums,vector<vector<int>> &dp, int index, int target, int n){
    if(target==0) return 1;
    if(target<0) return 0;
    if(index>=n) return 0;
    if(dp[index][target]!=-1) return dp[index][target];

    bool ans=solution1(nums,dp,index+1,target-nums[index],n);
    ans|=solution1(nums,dp,index+1,target,n);
    return dp[index][target]=ans;
}

//approach 3
bool solution2(vector<int> &nums){
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
        return false;
    sum = sum / 2;
    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0]=1;   //base condition
    }

    for (int index = n-1; index >=0; index--)
    {
        for (int target = 0; target <= sum; target++)
        {
            int ans=0;
            if(target-nums[index]>=0){
                ans=dp[index+1][target-nums[index]];
            }
            ans|=dp[index+1][target];
            dp[index][target]=ans;
        }
    }
    return dp[0][sum];
}

//approach 4
bool solution3(vector<int> &nums){
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
        return false;
    sum = sum / 2;
    vector<int>curr(sum+1,0);
    vector<int>next(sum+1,0);

    curr[0]=1;
    next[0]=1;

    for (int index = n-1; index >=0; index--)
    {
        for (int target = 0; target <= sum; target++)
        {
            int ans=0;
            if(target-nums[index]>=0){
                ans=next[target-nums[index]];
            }
            ans|=next[target];
            curr[target]=ans;
        }
        next=curr;
    }
    return next[sum];
}

bool canPartition(vector<int> &nums)
{
    //for approach 2
    // int n = nums.size();
    // int sum = accumulate(nums.begin(), nums.end(), 0);
    // if (sum % 2 != 0)
    //     return false;
    // sum = sum / 2;
    // vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    // return solution1(nums,dp,0,sum,n);

    //for approach 3
    // return solution2(nums);

    //for approach 4
    return solution3(nums);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
