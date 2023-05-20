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

int func(long long int a,long long int b, long long int m){
    int ans=1;
    while (b)
    {
        if (b&1)
        {
            ans=(ans*1LL*a)%m;
        }
        a=(a*1LL*a)%m;
        b=b>>1;
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int a,b=0,m=1e9+7,ans,len;
    string s;
    cin>>a>>s;
    len=s.length();
    for (int i = 0; i < len; i++)
    {
        b=(b*10+s[i]-'0')%(m-1);
    }
    ans=func(a,b,m);
    cout<<ans<<endl;
    return 0;
}
