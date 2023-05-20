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

// int kthSmallest(int arr[], int l, int r, int k)
// {
//     sort(arr,arr+r+1);
//     return arr[k-1];
// }

int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int>maxh;
    for (int i = l; i <=r; i++)
    {
        maxh.push(arr[i]);
        if (maxh.size()>k)
        {
            maxh.pop();
        }
    }
    return maxh.top();
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
