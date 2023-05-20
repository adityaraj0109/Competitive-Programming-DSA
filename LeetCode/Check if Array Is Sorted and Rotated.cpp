#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool check(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (!(nums[i + 1] >= nums[i]))
        {
            count++;
            if ((i + 2) < nums.size())
            {
                if (nums[i] < nums[i + 2])
                {
                    return false;
                }
            }
        }
    }
    if (nums[nums.size()-1]>nums[0])
    {
        count++;
    }
    if (count > 1)
    {
        return false;
    }
    return true;
}

int main()
{
    debugMode();
    vector<int> vec = {2, 1, 3, 4};
    bool ans = check(vec);
    cout << ans << endl;
    return 0;
}
