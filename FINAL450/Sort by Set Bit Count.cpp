#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

static bool compare(int a, int b){
    return __builtin_popcount(a)>__builtin_popcount(b);
}

void sortBySetBitCount(int arr[], int n)
{
    stable_sort(arr,arr+n,compare);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
