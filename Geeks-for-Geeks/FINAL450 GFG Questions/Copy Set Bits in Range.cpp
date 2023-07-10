#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int setSetBit(int x, int y, int l, int r)
{
    for (int i = l-1; i <r; i++)
    {
        if((1<<i)&y){
            x=x|(1<<i);
        }
    }
    return x;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
