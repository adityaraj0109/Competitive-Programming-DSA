#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int maxJumps(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (abs(nums[i] - nums[j]) <= target)
            {
                if (dp[j] != -1)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
    }

    return dp[n - 1];
}

int maximumJumps(vector<int> &nums, int target)
{
    return maxJumps(nums, target);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
