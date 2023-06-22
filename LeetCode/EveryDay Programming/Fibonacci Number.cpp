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

int fib(int n)
{
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    vector<int>v(n+1);
    v[0]=0,v[1]=1;
    for (int i = 2; i <= n; i++)
    {
        v[i]=v[i-1]+v[i-2];
    }
    return v[n];
}

int main()
{
    debugMode();
    cout<<fib(30);
    return 0;
}
