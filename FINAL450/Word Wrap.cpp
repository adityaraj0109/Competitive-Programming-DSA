#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int dp[500][2000];
int solution(vector<int> &nums, int k, int index, int rem){
    if(index>=nums.size()) return 0;
    if(dp[index][rem]!=-1) return dp[index][rem];
    int ans;
    if(nums[index]>rem){
        ans=(rem+1)*(rem+1)+solution(nums,k,index+1,k-nums[index]-1);
    }
    else{
        int take=solution(nums,k,index+1,rem-nums[index]-1);
        int notTake=(rem+1)*(rem+1)+solution(nums,k,index+1,k-nums[index]-1);
        ans=min(take,notTake);
    }
    return dp[index][rem]=ans;
}

int solveWordWrap(vector<int> nums, int k)
{
    memset(dp, -1, sizeof(dp));
    return solution(nums,k,0,k);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
