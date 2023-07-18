#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int maxSubStr(string str)
{
    int n=str.size();
    if(n%2!=0) return -1;
    int c0=0,c1=0;
    int ans=0;
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i]=='0') c0++;
        else c1++;
        if(c1==c0){
            ans++;
            c0=0,c1=0;
        }
    }
    if(ans==0 || c0!=0 || c1!=0) return -1;
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
