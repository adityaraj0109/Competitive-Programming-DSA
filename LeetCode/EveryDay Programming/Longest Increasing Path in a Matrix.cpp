#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int solution(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (i >= matrix.size() || j >= matrix[0].size())
        return 0;
    if (dp[i][j] != 0)
        return dp[i][j];

    int ans = 1;

    // up
    if (i - 1 >= 0 && matrix[i][j] < matrix[i - 1][j])
    {
        ans = max(ans, 1 + solution(matrix, dp, i - 1, j));
    }

    // right
    if (j + 1 < matrix[0].size() && matrix[i][j] < matrix[i][j + 1])
    {
        ans = max(ans, 1 + solution(matrix, dp, i, j + 1));
    }
    // down
    if (i + 1 < matrix.size() && matrix[i][j] < matrix[i + 1][j])
    {
        ans = max(ans, 1 + solution(matrix, dp, i + 1, j));
    }
    // left
    if (j - 1 >= 0 && matrix[i][j] < matrix[i][j - 1])
    {
        ans = max(ans, 1 + solution(matrix, dp, i, j - 1));
    }

    return dp[i][j] = ans;
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, solution(matrix, dp, i, j));
        }
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