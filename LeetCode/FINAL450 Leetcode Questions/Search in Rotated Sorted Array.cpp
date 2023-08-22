#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int search(vector<int> &nums, int target)
{
    int high=nums.size()-1,low=0;
    while (high>=low)
    {
        int mid=(high+low)/2;
        if(target==nums[mid]) return mid;
        if(nums[mid]>=nums[low]){
            if(target<nums[mid] && target>=nums[low]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(target>nums[mid] && target<=nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
