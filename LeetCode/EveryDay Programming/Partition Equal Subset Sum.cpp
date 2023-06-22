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

int dp[205][20005];

bool solution(int index, int sum, vector<int> &nums)
{
    if (sum == 0)
        return true;
    if (index < 0)
        return false;
    if (dp[index][sum] != -1)
        return dp[index][sum];

    bool ans = solution(index - 1, sum, nums);
    if (sum - nums[index] >= 0)
    {
        ans |= solution(index - 1, sum - nums[index], nums);
    }
    return dp[index][sum] = ans;
}

bool canPartition(vector<int> &nums)
{
    memset(dp, -1, sizeof(dp));
    int n = nums.size() - 1;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
        return false;
    sum = sum / 2;
    return solution(n, sum, nums);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
