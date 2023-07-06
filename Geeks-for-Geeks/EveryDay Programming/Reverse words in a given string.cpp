#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string reverseWords(string S)
{
    string ans="";
    string temp="";
    for (int i =S.size()-1; i >=0 ; i--)
    {
        if(S[i]=='.'){
            reverse(temp.begin(),temp.end());
            ans=ans+temp;
            temp="";
            ans=ans+'.';
        }
        else{
            temp=temp+S[i];
        }
    }
    reverse(temp.begin(),temp.end());
    ans=ans+temp;
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
