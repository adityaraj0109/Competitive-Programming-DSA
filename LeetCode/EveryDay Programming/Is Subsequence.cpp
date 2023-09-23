#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool isSubsequence(string s, string t)
{
    if(s==t) return true;
    int j=0;
    for (int i = 0; i < t.size(); i++)
    {
        if(s[j]==t[i]) j++;
        if(j==s.size()) return true;
    }
    return false;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < ; i++)
    {
        /* code */
    }
    return 0;
}
