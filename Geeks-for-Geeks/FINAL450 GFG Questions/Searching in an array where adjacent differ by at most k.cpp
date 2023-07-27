#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int search(int arr[], int n, int x, int k)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==x) return i;
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
