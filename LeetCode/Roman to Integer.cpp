#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int romanToInt(string s) {
    unordered_map<char,int>m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int ans=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(i+1<n && m[s[i]]<m[s[i+1]]){
            ans+=(m[s[i+1]]-m[s[i]]);
            i++;
        } 
        else ans+=m[s[i]];
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
