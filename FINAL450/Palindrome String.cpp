#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int isPalindrome(string S)
{
    for (int i = 0; i < (S.size()/2); i++)
    {
        if (S[i]!= S[S.size()-1-i]){
            return 0;
        }
    }
    return 1;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
