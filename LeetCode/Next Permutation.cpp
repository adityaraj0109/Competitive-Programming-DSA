#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void nextPermutation(vector<int> &nums)
{
    int i;
    for (i = nums.size()-2; i >=0; i--)
    {
        if(nums[i]<nums[i+1]){
            break;
        }
    }
    if(i<0){
        reverse(nums.begin(), nums.end());
    }
    else{
        for (int j = nums.size()-1; j >= 0; j--)
        {
            if(nums[i]<nums[j]){
                swap(nums[i],nums[j]);
                break;
            }
        }
        reverse(nums.begin()+i+1,nums.end());
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
