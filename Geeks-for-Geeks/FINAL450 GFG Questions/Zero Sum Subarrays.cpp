#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

long long int findSubarray(vector<long long int> &arr, int n ) {
    unordered_map<long long int,long long int>m;
    long long int sum=0;
    m[sum]++;
    long long int count=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        if(m[sum]!=0) count+=m[sum];
        m[sum]++;
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
