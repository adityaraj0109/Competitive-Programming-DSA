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

//nlogn approach
// vector<int> findDuplicates(vector<int> &nums)
// {
//     vector<int> v;
//     sort(nums.begin(), nums.end());
//     int count = 1;
//     for (int i = 1; i < nums.size(); i++)
//     {
//         if (nums[i] != nums[i - 1])
//         {
//             if (count == 2)
//             {
//                 v.push_back(nums[i - 1]);
//             }
//             count = 1;
//         }
//         else
//         {
//             count++;
//             if (i == nums.size() - 1)
//             {
//                 if (count == 2)
//                 {
//                     v.push_back(nums[i - 1]);
//                 }
//             }
//         }
//     }
//     return v;
// }

vector<int> findDuplicates(vector<int>& nums) 
{
    vector<int>ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) ans.push_back(abs(nums[i]));
        else nums[index] = -1*nums[index];
    }
    return ans;
}

int main()
{
    debugMode();
    vector<int> v = {1, 1};
    vector<int> ans = findDuplicates(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
