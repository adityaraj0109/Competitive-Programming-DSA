#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool areRotations(string s1, string s2)
{
    if(s1.length()!=s2.length()) return false;
    s1=s1+s1;
    int n=s1.size();
    if(s1.find(s2)==string::npos) return false;
    return true;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
