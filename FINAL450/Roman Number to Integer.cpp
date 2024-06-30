#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int romanToDecimal(string &str)
{
    unordered_map<char,int>m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    if(str.size()==1) return m[str[0]];
    int value=m[str[str.size()-1]];
    for (int i = str.size()-2; i >=0; i--)
    {
        if(m[str[i+1]]>m[str[i]]){
            value-=m[str[i]];
        }
        else value+=m[str[i]];
    }
    return value;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
