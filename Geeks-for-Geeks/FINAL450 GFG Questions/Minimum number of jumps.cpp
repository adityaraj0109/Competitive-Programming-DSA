#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int minJumps(int arr[], int n)
{
    if(n==1){
        return 0;
    }
    if (arr[0]==0)
    {
        return -1;
    }
    int maxi=arr[0];
    int jumps=1;
    int steps=arr[0];
    for (int i = 1; i < n; i++)
    {
        if(i==n-1){
            return jumps;
        }
        steps--;
        maxi=max(maxi,arr[i]+i);
        if (steps==0)
        {
            jumps++;
            steps=maxi-i;
            if (steps==0)
            {
                return -1;
            }
        }
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
