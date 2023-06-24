#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// approach 1
int solution1(vector<int> &values, vector<vector<int>> &dp, int i, int j)
{
    if (i + 1 == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, values[i] * values[j] * values[k] + solution1(values, dp, i, k) + solution1(values, dp, k, j));
    }
    return dp[i][j] = ans;
}

// approach 1
int solution2(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n-1; i >=0; i--)
    {
        for (int j = i+2; j < n; j++)
        {
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                ans = min(ans, values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]);
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][n - 1];
}

int minScoreTriangulation(vector<int> &values)
{
    // for approach 1
    //  int n=values.size();
    //  vector<vector<int>>dp(n,vector<int>(n,-1));
    //  return solution1(values,dp,0,n-1);

    // for approach 2
    return solution2(values);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
