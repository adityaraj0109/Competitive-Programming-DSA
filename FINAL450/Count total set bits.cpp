#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int countSetBits(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    int x=log2(n);
    return ((1<<(x-1))*x)+(n-pow(2,x)+1)+countSetBits(n-(1<<x));
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
