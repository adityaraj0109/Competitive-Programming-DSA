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

string removeOccurrences(string s, string part)
{
    auto it=s.find(part);
    int len=part.length();
    while (it!=string::npos)
    {
        s.erase(s.begin()+it,s.begin()+it+len);
        it=s.find(part);
    }
    return s;
}

int main()
{
    debugMode();
    string s = "daabcbaabcbc", part = "abc";
    string ans = removeOccurrences(s,part);
    cout << ans << endl;
    return 0;
}
