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

int m = 1e6 + 3;
vector<int> fact(m);

void factorial()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < m; i++)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % m;
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    factorial();
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, x;
        cin >> n >> x;
        x = x % m;
        if (n >= m)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << (x * 1LL * fact[n]) % m << endl;
        }
    }
    return 0;
}
