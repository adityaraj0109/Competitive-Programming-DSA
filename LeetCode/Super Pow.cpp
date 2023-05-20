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

vector<int> sieve()
{
    int N = 1350;
    vector<int> lp(N, 0), hp(N, 0);
    vector<int> isprime(N, 1);
    int m = 1337;
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            lp[i] = i, hp[i] = i;
            for (int j = 2 * i; j < N; j = j + i)
            {
                isprime[j] = 0;
                hp[j] = i;
                if (lp[j] == 0)
                {
                    lp[j] = i;
                }
            }
        }
    }
    return lp;
}

unordered_set<int> primefactor(int n)
{
    vector<int>lp=sieve();
    unordered_set<int> prime;
    while (n > 1)
    {
        if (n % lp[n] == 0)
        {
            prime.insert(lp[n]);
            n = n / lp[n];
        }
    }
    return prime;
}

int Eular_totient(int n)
{
    unordered_set<int> prime = primefactor(n);
    float result = n;
    for (auto it : prime)
    {
        result *= (1.0 - (1.0 / (float)it));
    }
    return (int)result;
}

int binary(int a, int b)
{
    int ans = 1,m=1337;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return ans;
}

int superPow(int a, vector<int> &b)
{
    int m=1337;
    a = a % m;
    int power = 0;
    for (int i = 0; i < b.size(); i++)
    {
        power = (power * 10 + b[i]) % Eular_totient(m);
    }
    int ans = binary(a, power) % m;
    return ans;
}

int main()
{
    debugMode();
    vector<int> v = {1, 0};
    int ans = superPow(2, v);
    cout << ans << endl;
    return 0;
}
