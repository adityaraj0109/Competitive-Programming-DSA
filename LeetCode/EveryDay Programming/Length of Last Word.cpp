#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int lengthOfLastWord(string s) {
    int n=s.size();
    int r=n-1,l;
    while (r>=0)
    {
        if (s[r]!=' '){
            break;
        }
        r--;
    }
    l=r;
    while (l>=0)
    {
        if(s[l]==' ') break;
        l--;
    }
    return r-l;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
