#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int solution(vector<int> &nums){
    int n = nums.size();
    unordered_map<int, int> m;
    int maxm = 0,domelem = 0,count = 0;

    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
        if (m[nums[i]] > maxm)
        {
            maxm = m[nums[i]];
            domelem = nums[i];
            count = maxm;
        }
    }
    if (count * 2 <= n)
    {
        return -1;
    }
    int leftm = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == domelem)
        {
            leftm++;
        }
        int rightm = count - leftm;
        if (leftm * 2 > i + 1 && rightm * 2 > n - i - 1)
        {
            return i;
        }
    }
    return -1;
}

int minimumIndex(vector<int> &nums)
{
    return solution(nums);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
