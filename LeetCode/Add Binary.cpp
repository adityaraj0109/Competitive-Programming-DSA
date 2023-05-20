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

string addBinary(string a, string b)
{
    while (a.length()!=b.length())
    {
        if (a.length()>b.length())
        {
            b="0"+b;
        }
        else
        {
            a="0"+a;
        }
    }
    int carry=0;
    string ans="";
    for(int i=a.size()-1;i>=0;i--){
        if (a[i]=='0' && b[i]=='0')
        {
            if (carry)
            {
                ans="1"+ans;
                carry=0;
            }
            else{
                ans="0"+ans;
            }
        }
        else if (a[i]=='0' && b[i]=='1')
        {
            if (carry)
            {
                ans="0"+ans;
            }
            else{
                ans="1"+ans;
            }
        }
        else if (a[i]=='1' && b[i]=='0')
        {
            if (carry)
            {
                ans="0"+ans;
            }
            else{
                ans="1"+ans;
            }
        }
        else{
            if (carry)
            {
                ans="1"+ans;
            }
            else{
                ans="0"+ans;
                carry=1;
            }
        }
    }
    if (carry)
    {
        return ("1"+ans);
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<addBinary("11","1")<<endl;
    return 0;
}
