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

int distinctIntegers(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n - 1;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    make_array();
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, l, s;
        cin >> n >> l >> s;
        if (has_subarray(n, l, s))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
