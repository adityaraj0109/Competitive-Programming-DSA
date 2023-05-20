#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int m=10000007;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int func(int a,int b){
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
    while (true)
    {
        int n,k;
        cin>>n>>k;
        if (n==0 && k==0)
        {
            break;
        }
        vector<int>v(4);
        v[0]=(2*(func((n-1),k)))%m;
        v[1]=(2*(func((n-1),(n-1))))%m;
        v[2]=(func(n,k))%m;
        v[3]=(func(n,n))%m;
        int sum=0;
        for (int i = 0; i < 4; i++)
        {
            sum=(sum+v[i])%m;
        }
        cout<<sum<<endl;
    }
    return 0;
}
