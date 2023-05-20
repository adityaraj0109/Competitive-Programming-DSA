#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if (s==t)
    {
        return true;
    }
    return false;
}

int main()
{
    string s,t;
    cin>>s>>t;
    bool ans=isAnagram(s,t);
    cout<<ans<<endl;
    return 0;
}