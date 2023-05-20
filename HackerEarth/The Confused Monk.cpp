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

int m=1e9+7;

int binary(int a,int b){
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
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int f=1,g=0;
    for (int i = 0; i < n; i++)
    {
        g=__gcd(g,nums[i]);
        f=(f*1LL*nums[i])%m;
    }
    int ans=binary(f,g);
    cout<<ans<<endl;
    return 0;
}