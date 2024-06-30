#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int lengthOfLongestSubstring(string s)
{
    unordered_map<char,int>m;
    int n = s.length();
    if (n == 0) return 0;
    int left=0,ans=1;
    m[s[left]]=0;
    for (int right = 1; right < n; right++)
    {
        if(m.find(s[right])!=m.end()) left=max(m[s[right]]+1,left);
        m[s[right]]=right;
        ans=max(ans,right-left+1);
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
