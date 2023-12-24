#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string restoreString(string s, vector<int> &indices)
{
    string str=s;
    for(int i=0;i<indices.size();i++){
        str[indices[i]]=s[i];
    }
    return str;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
