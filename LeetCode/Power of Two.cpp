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

bool isPowerOfTwo(int n)
{
    if (n<0)
    {
        return false;
    }
    int m=__builtin_popcount(n);
    if (m==1)
    {
        return true;
    }
    return false;
}

int main()
{
    debugMode();
    cout<<INT_MIN<<endl;
    int ans = isPowerOfTwo(2147483648);
    cout << ans << endl;
    return 0;
}
