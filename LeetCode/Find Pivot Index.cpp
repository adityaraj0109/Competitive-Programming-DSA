#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int pivotIndex(vector<int>& nums) {
    int n=nums.size();
    vector<int>left(n,0);
    vector<int>right(n,0);
    long long sum1=nums[0],sum2=nums[n-1];
    for (int i = 1; i < n; i++)
    {
        left[i]=sum1;
        sum1+=nums[i];
        right[n-1-i]=sum2;
        sum2+=nums[n-i-1];
    }
    for (int i = 0; i < n; i++)
    {
        if(left[i]==right[i]) return i;
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
