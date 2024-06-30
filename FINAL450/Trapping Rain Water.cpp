#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

long long trappingWater(int arr[], int n)
{
    vector<int>left(n);
    vector<int>right(n);
    left[0]=arr[0];
    right[n-1]=arr[n-1];
    for (int i = 1; i < n; i++)
    {
        left[i]=max(left[i-1],arr[i]);
        right[n-i-1]=max(right[n-i],arr[n-i-1]);
    }
    long long ans=0;
    for (int i = 0; i < n; i++)
    {
        ans+=min(left[i],right[i])-arr[i];
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
