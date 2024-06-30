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

void reverseString(vector<char> &s)
{
    for (int i = 0; i < s.size()/2; i++)
    {
        swap(s[i],s[s.size()-1-i]);
    }
}

int main()
{
    debugMode();
    vector<char> v = {'h','e','l','l','o','a'};
    reverseString(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
