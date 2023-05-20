#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool isPalindrome(string s)
{
    string str="";
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        {
            str+=s[i];
        }
        if (s[i]>='A' && s[i]<='Z')
        {
            str+=tolower(s[i]);
        }
    }
    string ss=str;
    reverse(ss.begin(),ss.end());
    if (ss==str)
    {
        return true;
    }
    return false;
}

int main()
{
    debugMode();
    string s=" ";
    cout<<isPalindrome(s)<<endl;
    return 0;
}
