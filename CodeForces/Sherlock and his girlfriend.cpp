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

void sieve(int n)
{
    vector<int> isprime(n+2, 1);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i < n+2; i++)
    {
        if (isprime[i])
        {
            int k=1;
            for (int j = 2 * i; j < n+2; j = j + i)
            {

                isprime[j] = 2;
            }
        }
    }
    cout<<2<<endl;
    for (int i = 2; i < n+2; i++)
    {
        cout<<isprime[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if (n==1)
    {
        cout<<1<<endl<<1<<endl;
    }
    else if (n==2)
    {
        cout<<1<<endl;
        cout<<1<<" "<<1<<endl;
    }
    else
    {
        sieve(n);
    }
    return 0;
}
