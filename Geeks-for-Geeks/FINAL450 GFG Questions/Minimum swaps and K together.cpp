#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int minSwap(int arr[], int n, int k)
{
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<=k){
            count++;
        }
    }
    int low=0,high=count-1;
    int ans=INT_MAX;
    int temp=0;
    for (int i = 0; i < count; i++)
    {
        if(arr[i]>k){
            temp++;
        }
    }
    ans=min(ans,temp);
    while (high<n-1)
    {
        high++;
        if(arr[high]>k) temp++;
        if(arr[low]>k) temp--;
        low++;
        ans=min(ans,temp);
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
