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

void rotate(vector<int> &nums, int k)
{
    vector<int>temp(nums.size());
    for (int i = 0; i <nums.size() ; i++)
    {
        temp[(i+k)%nums.size()]=nums[i];
    }
    for (int i = 0; i <nums.size() ; i++)
    {
        nums[i]=temp[i];
    }
}

int main()
{
    debugMode();
    vector<int>vec={1,2,3,4,5,6,7};
    rotate(vec,3);
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;
}
