#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string longestPalin(string S)
{
    int count=INT_MIN;
    string ans="";
    for (int i = 0; i < S.size(); i++)
    {
        //for odd
        int l=i-1,r=i+1;
        while (l>=0 && r<S.size() && S[l]==S[r])
        {
            l--,r++;
        }
        l++,r--;
        if (r-l+1>count){
            count=r-l+1;
            ans=S.substr(l,count);
        }

        //for even
        l=i;r=i+1;
        while (l>=0 && r<S.size() && S[l]==S[r])
        {
            l--,r++;
        }
        l++,r--;
        if (r-l+1>count){
            count=r-l+1;
            ans=S.substr(l,count);
        }
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
