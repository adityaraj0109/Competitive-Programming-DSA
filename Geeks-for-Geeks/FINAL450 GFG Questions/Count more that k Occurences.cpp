#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int countOccurence(int arr[], int n, int k)
{
    unordered_map<int,int>m;
    int count=0;
    int freq=n/k;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (auto it : m){
        if(it.second>freq){
            count++;
        }
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
