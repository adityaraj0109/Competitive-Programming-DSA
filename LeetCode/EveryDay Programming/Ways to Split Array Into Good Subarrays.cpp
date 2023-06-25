#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int numberOfGoodSubarraySplits(vector<int> &nums)
{
    long long count = 0;
    long long ways = 1;
    int index = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            index = i;
            break;
        }
    }

    if (index == nums.size())
    {
        return 0;
    }

    for (int i = index; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            count++; // Increment count for zeros
        }
        else
        {
            ways = (ways * (count + 1)) % 1000000007;
            count = 0;
        }
    }

    return ways;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
