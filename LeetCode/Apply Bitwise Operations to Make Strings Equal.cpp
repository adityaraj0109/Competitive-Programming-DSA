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

bool makeStringsEqual(string s, string target) {
    int c1=0,c3=0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='1')
        {
            c1++;
        }
        if (target[i]=='1')
        {
            c3++;
        }
    }
    if (c1==0 || c3==0)
    {
        if (c1==c3)
        {
            return true;
        }
        return false;
    }
    return true; 
}

int main()
{
    debugMode();
    return 0;
}
