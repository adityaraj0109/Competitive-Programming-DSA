#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int i=n-1;
    int j=0;
    while (i>=0 && j<m && arr1[i]>arr2[j])
    {
        swap(arr1[i],arr2[j]);
        i--;
        j++;
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
