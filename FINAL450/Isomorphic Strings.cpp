#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool areIsomorphic(string str1, string str2)
{
    if(str1.size()!=str2.size()) return false;
    unordered_map<char,char>m1;
    unordered_map<char,char>m2;
    for (int i = 0; i < str1.size(); i++)
    {
        if(m1.find(str1[i])==m1.end() && m2.find(str2[i])==m2.end()){
            m1[str1[i]]=str2[i];
            m2[str2[i]]=str1[i];
        }
        else{
            if(m1[str1[i]]!=str2[i] || m2[str2[i]]!=str1[i]) return false;
        }
    }
    return true;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
