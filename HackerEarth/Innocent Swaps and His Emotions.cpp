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
int num=1e6+10;
vector<int>fact(num);

void factorial(){
    fact[0]=fact[1]=1;
    for (int i = 2; i < num; i++)
    {
        fact[i]=(i*1LL*fact[i-1])%m;
    }
}

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
    factorial();
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        int num=(binary(2,k)*1LL*fact[n])%m;
        int deno=(fact[k]*1LL*fact[n-k])%m;
        int answer=(num*1LL*binary(deno,m-2))%m;
        cout<<answer<<endl;
    }
    return 0;
}
