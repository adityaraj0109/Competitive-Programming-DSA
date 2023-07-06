#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(),a.end());
    long long ans=LONG_LONG_MAX;
    int i=0,j=m-1;
    while (j<n)
    {
        ans=min(ans,(a[j]-a[i]));
        i++;j++;
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
