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

bool isPalindrome(int x) {
    string str=to_string(x);
    string s=str;
    reverse(str.begin(),str.end());
    if (s==str)
    {
        return true;
    }
    return false;
}

int main()
{
    debugMode();
    int n;
    cin>>n;
    bool ans=isPalindrome(n);
    cout<<ans<<endl;
    return 0;
}
