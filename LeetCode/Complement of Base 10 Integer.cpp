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

int bitwiseComplement(int n)
{
    if (n==0)
    {
        return 1;
    }
    int digit=log2(n)+1;
    for (int i = 0; i < digit; i++)
    {
        n=n^(1<<i);
    }
    return n;
}

int main()
{
    debugMode();
    int ans=bitwiseComplement(5);
    cout<<ans<<endl;
    return 0;
}
