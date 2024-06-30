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

int m = 1e9 + 7;

long int solution(int N, vector<int> &dp)
{
    if (N == 1)
        return 0;
    if (N == 2)
        return 1;
    if (dp[N] != -1)
        return dp[N];

    long int ans = (((N - 1) % m) * (solution(N - 1, dp) % m + solution(N - 2, dp) % m) % m) % m;
    return dp[N] = ans;
}

long int disarrange(int N)
{
    vector<int> dp(N + 1, -1);
    return solution(N, dp);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
