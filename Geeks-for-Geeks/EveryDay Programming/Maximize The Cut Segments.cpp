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

int solution(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    if (dp[n] != -1)
        return dp[n];

    int ans = solution(n - x, x, y, z, dp) + 1;
    ans = max(ans, solution(n - y, x, y, z, dp) + 1);
    ans = max(ans, solution(n - z, x, y, z, dp) + 1);
    return dp[n] = ans;
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    int ans = solution(n, x, y, z, dp);
    if (ans < 0)
    {
        return 0;
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
