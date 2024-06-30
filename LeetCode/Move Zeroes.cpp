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

void moveZeroes(vector<int> &nums)
{
    int j=0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i]!=0)
        {
            swap(nums[j],nums[i]);
            j++;
        }
    }
}

int main()
{
    debugMode();
    vector<int>nums={0,1,0,3,12};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}
