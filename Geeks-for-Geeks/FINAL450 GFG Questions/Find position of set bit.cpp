#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int findPosition(int N)
{
    if(__builtin_popcount(N)>1 || N==0){
        return -1;
    }
    int count=0;
    while (N>0)
    {
        count++;
        N=N/2;
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
