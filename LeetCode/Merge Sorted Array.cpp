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

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = m; i < nums1.size(); i++)
    {
        nums1[i]=nums2[i-m];
    }
    sort(nums1.begin(),nums1.end());
}

int main()
{
    debugMode();
    vector<int> v1 = {1,2,3,0,0,0};
    vector<int> v2 = {2,5,6};
    merge(v1,3,v2,3);
    return 0;
}
