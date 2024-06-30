#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string longestPalindrome(string s) {
    int n=s.size();
    string ans="";
    int count=0;
    for (int i = 0; i < n; ++i){
        //odd case
        int l=i-1,r=i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            l--,r++;
        }
        l++,r--;
        if(r-l+1 > count){
            count=r-l+1;
            ans=s.substr(l,count);
        }

        //even case
        l=i, r=i+1;
        while (l>=0 && r<n && s[l]==s[r])
        {
            l--,r++;
        }
        l++,r--;
        if(r-l+1 > count){
            count=r-l+1;
            ans=s.substr(l,count);
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
