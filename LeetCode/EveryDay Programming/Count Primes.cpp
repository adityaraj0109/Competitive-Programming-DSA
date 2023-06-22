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

int sieve(int n)
{
    int count=0;
    vector<int> isprime(n, 1);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i < n; i++)
    {
        if (isprime[i])
        {
            count++;
            for (int j = 2 * i; j < n; j = j + i)
            {
                isprime[j] = 0;
            }
        }
    }
    return count;
}

int countPrimes(int n)
{
    if (n==0 || n==1)
    {
        return 0;
    }
    return sieve(n);
}

int main()
{
    debugMode();
    int ans=countPrimes(10);
    cout<<ans<<endl;
    return 0;
}
