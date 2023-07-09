#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int,int>m;
    for (int i = 1; i < n; i++)
    {
        m[arr[i]]++;
    }
    int count=0;
    for (int i = 1; i < n; i++)
    {
        int val=k-arr[i-1];
        if(m[val]>0){
            count=count+m[val];
        }
        m[arr[i]]--;
    }
    return count;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
