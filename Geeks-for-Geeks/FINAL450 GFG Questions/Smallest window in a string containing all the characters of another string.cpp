#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string smallestWindow (string s, string p)
{
    int count=0;
    vector<int>arr(26,0);
    for (int i = 0; i < p.length(); i++)
    {
        arr[p[i]-'a']++;
        if(arr[p[i]-'a']==1) count++;
    }
    int mini=INT_MAX;
    int start=0,i=0,j=0;
    while (j<s.length())
    {
        arr[s[j]-'a']--;
        if(arr[s[j]-'a']==0) count--;
        if(count==0){
            while (count==0)
            {
                if(j-i+1<mini){
                    mini=j-i+1;
                    start=i;
                }
                arr[s[i]-'a']++;
                if(arr[s[i]-'a']==1) count++;
                i++;
            }
        }
        j++;
    }
    if(mini==INT_MAX) return "-1";
    return s.substr(start,mini);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
