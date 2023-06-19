#include <bits/stdc++.h>
#define ll long long
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int findValueOfPartition(vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    int minimum=INT_MAX;
    for (int i=0;i<nums.size()-1;i++){
        int diff=abs(nums[i]-nums[i+1]);
        minimum=min(minimum,diff);
    }
    return minimum;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
