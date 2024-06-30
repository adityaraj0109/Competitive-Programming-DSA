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

int getMinDiff(int arr[], int n, int k)
{
    sort(arr,arr+n);
    int mini=arr[0];
    int maxi=arr[n-1];
    int diff=maxi-mini;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]-k<0) continue;
        maxi=max(arr[i-1]+k,arr[n-1]-k);
        mini=min(arr[0]+k,arr[i]-k);
        diff=min(diff,maxi-mini);
    }
    return diff;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
