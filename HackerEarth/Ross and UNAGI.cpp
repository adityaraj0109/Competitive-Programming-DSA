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

int N=1e6+3;
vector<int>lp(N,0),hp(N,0);
vector<int>isprime(N,1);

void sieve_algo()
{
    isprime[0]=isprime[1]=0;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            lp[i]=hp[i]=i;
            for (int j = 2*i; j < N; j=j+i)
            {
                isprime[j]=0;
                hp[j]=i;
                if (lp[j]==0)
                {
                    lp[j]=i;
                }
            }
        }
    }
}

int prime_factorization_sieve(long long int n,int m)  //logn is the complexity here
{
    int sum=0;
    while (n>1)
    {
        if (n%lp[n]==0)
        {
            sum=(sum+lp[n])%m;
            n=n/lp[n];
        }
    }
    return sum;
}

int func(long long int a, long long int b, long long int m)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b = b >> 1;
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve_algo();
    int q;
    cin >> q;
    int m = 1e6 + 3;
    while (q--)
    {
        long long int a, b,c, ans;
        int ans1;
        cin >> a >> b>>c;
        b=func(b,c,(m-1));
        ans = (func(a, b, m)+1)%m;
        ans1=prime_factorization_sieve(ans,m);  
        cout<<ans1<<endl;      
    }
    return 0;
}
