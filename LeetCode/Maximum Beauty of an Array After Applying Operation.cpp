#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int maximumBeauty(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        m[nums[i] - k]++;
        m[nums[i] + k + 1]--;
    }
    vector<int> vec;
    for (auto it : m)
    {
        vec.push_back(it.first);
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    int count = 0;
    for (int it : vec)
    {
        count += m[it];
        ans = max(ans, count);
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}