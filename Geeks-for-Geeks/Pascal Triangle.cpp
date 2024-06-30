#include <bits/stdc++.h>
#define ll long long
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<ll> nthRowOfPascalTriangle(int n)
{
    int m = 1e9 + 7;
    vector<ll> ans;
    ans.push_back(1);
    if (n == 1)
    {
        return ans;
    }
    ans.push_back(1);
    for (int i = 2; i < n; i++)
    {
        vector<ll> temp;
        temp.push_back(1);
        for (int j = 1; j < i; j++)
        {
            ll sum = (ans[j] + ans[j - 1]) % m;
            temp.push_back(sum);
        }
        temp.push_back(1);
        ans = temp;
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
