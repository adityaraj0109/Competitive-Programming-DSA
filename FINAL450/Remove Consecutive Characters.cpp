#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string removeConsecutiveCharacter(string S)
{
    string str="";
    str+=S[0];
    for (int i = 1; i < S.length(); i++)
    {
        if(S[i]!=S[i-1]){
            str+=S[i];
        }
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
