#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

long long countFairPairs(vector<int> &nums, int lower, int upper)
{
    long long count = 0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++){
        int l=lower-nums[i];
        int r=upper-nums[i];
        count+=upper_bound(nums.begin()+i+1,nums.end(),r)-lower_bound(nums.begin()+i+1,nums.end(),l);
    }
    return count;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
