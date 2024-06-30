#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if(n==1) return nums[0];
    int low = 0, high = n - 1;
    while (low<=high){
        int mid = low + (high - low) / 2;
        if(mid > 0 && mid < n-1){
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            if(mid%2==1){
                if(nums[mid] == nums[mid-1]) low = mid+1;
                else high=mid-1;
            }
            else{
                if(nums[mid] == nums[mid-1]) high = mid-1;
                else low = mid+1;
            }
        }
        else if(mid==0){
            if(nums[mid]!=nums[mid+1]) return nums[mid];
            else low=mid+1;
        }
        else{
            if(nums[mid]!=nums[mid-1]) return nums[mid];
            else high=mid-1;
        }
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
