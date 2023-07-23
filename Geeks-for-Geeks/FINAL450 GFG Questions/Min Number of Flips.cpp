#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int minFlips (string S)
{
    int n=S.size();
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        if(i%2==0){
            if(S[i]=='1') ans++;
        }
        else{
            if(S[i]=='0') ans++;
        }
    }
    return min(ans,n-ans);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
