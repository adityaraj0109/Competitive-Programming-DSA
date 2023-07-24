#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int findSubString(string str)
{
    unordered_set<char>s;
    for (int i = 0; i < str.length(); i++)
    {
        s.insert(str[i]);
    }
    int num=s.size();
    unordered_map<char,int>m;
    int start=0,mini=INT_MAX,count=0;
    for(int i=0;i<str.length();i++){
        m[str[i]]++;
        if(m.size()==num){
            while(m[str[start]]>1){
            m[str[start]]--;
            start++;
            }
            mini=min(mini,i-start+1);
        }
    }
    return mini;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
