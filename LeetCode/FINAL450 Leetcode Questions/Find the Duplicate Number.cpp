#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//brute force sort and check if arr[i]==arr[i+1]
//better approach
// int findDuplicate(vector<int> &nums)
// {
//     vector<int>temp(nums.size()+1,0);
//     int ans;
//     for(int i=0;i<nums.size();i++){
//         temp[nums[i]]++;
//         if (temp[nums[i]]>1)
//         {
//             ans= nums[i];
//             break;
//         }
//     }
//     return ans;
// }

//approach of linked list in arrays
int findDuplicate(vector<int> &nums)
{
    int slow=nums[0];
    int fast=nums[0];

    do
    {
        slow=nums[slow];
        fast=nums[nums[fast]];
    } while (slow!=fast);

    fast=nums[0];
    while (fast!=slow)
    {
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
