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

int peakIndexInMountainArray(vector<int> &arr)
{
    int low=0,high=arr.size()-1;
    int mid=(low+high)/2;
    while (high>low)
    {
        mid=(low+high)/2;
        if (arr[mid]<arr[mid+1])
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    return high;
}

int main()
{
    debugMode();
    vector<int> v = {0,2,1,0};
    int ans = peakIndexInMountainArray(v);
    cout<<ans<<endl;
    return 0;
}
