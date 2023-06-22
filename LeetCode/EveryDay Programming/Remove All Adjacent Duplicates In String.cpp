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

string removeDuplicates(string s)
{
    for (int i = 0; i < s.length()-1; i++)
    {
        if (s[i]==s[i+1])
        {
            s.erase(i,2);
            if (s.length()==0)
            {
                break;
            }
            if (i!=0)
            {
                i=i-2;
            }
            else
            {
                i=i-1;
            }
        }
    }
    return s;
}

int main()
{
    debugMode();
    string s = "aaaaaaaa";
    string ans = removeDuplicates(s);
    cout << ans << endl;
    return 0;
}
