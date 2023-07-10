#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int find_median(vector<int> v)
{
    int n=v.size();
    sort(v.begin(),v.end());
    if(n%2==0){
        return (v[n/2]+v[n/2-1])/2;
    }
    return v[n/2];
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
