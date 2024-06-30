#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//Approach 1
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

//Approach 2
int findPivot(vector<int> &nums){
    int low=0;
    int high=nums.size()-1;
    int mid=(low+high)/2;
    while (low<high)
    {
        if(nums[mid]>=nums[0]) low=mid+1;
        else high=mid;
        mid=(low+high)/2;
    }
    return mid;
}

int binarySearch(vector<int>&nums, int target, int low, int high){
    int mid=(low+high)/2;
    while (low<=high)
    {
        if(nums[mid]==target) return mid;
        if(nums[mid]<target) low=mid+1;
        else high=mid-1;
        mid=(low+high)/2;
    }
    return -1;
}

int solution(vector<int>&nums, int target){
    int pivot=findPivot(nums);
    int n=nums.size();
    if(target>=nums[pivot] && target<=nums[n-1]) return binarySearch(nums,target,pivot,n-1);
    return binarySearch(nums,target,0,pivot-1);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
