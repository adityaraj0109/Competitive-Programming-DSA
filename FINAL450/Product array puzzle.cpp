#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    if(nums.size()==1) return {1};
    vector<long long int>ans;
    vector<long long int>left(n,1);
    vector<long long int>right(n,1);
    left[0]=nums[0];
    right[n-1]=nums[n-1];
    for (int i = 1; i < n; i++)
    {
        left[i]=nums[i]*left[i-1];
        right[n-i-1]=nums[n-i-1]*right[n-i];
    }
    ans.push_back(right[1]);
    for (int i = 1; i < n-1; i++)
    {
        ans.push_back(left[i-1]*right[i+1]);
    }
    ans.push_back(left[n-2]);
    return ans;
}  

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
