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
int solution1(vector<int> &obstacles, vector<vector<int>> &dp, int curlane, int curpos, int n)
{
    if (curpos == n)
        return 0;
    if (dp[curlane][curpos] != -1)
        return dp[curlane][curpos];

    if (obstacles[curpos + 1] != curlane)
    {
        return dp[curlane][curpos] = solution1(obstacles, dp, curlane, curpos + 1, n);
    }
    else
    {
        int ans = INT_MAX;
        for (int i = 1; i < 4; i++)
        {
            if (curlane != i && obstacles[curpos] != i)
            {
                ans = min(ans, 1 + solution1(obstacles, dp, i, curpos, n));
            }
        }
        return dp[curlane][curpos] = ans;
    }
}

// approach 2
int solution2(vector<int> &obstacles)
{
    int n = obstacles.size();
    vector<vector<int>> dp(4, vector<int>(n, 1e9));

    dp[0][n - 1] = 0;
    dp[1][n - 1] = 0;
    dp[2][n - 1] = 0;
    dp[3][n - 1] = 0;

    for (int curpos = n - 2; curpos >= 0; curpos--)
    {
        for (int curlane = 1; curlane <= 3; curlane++)
        {
            if (obstacles[curpos + 1] != curlane)
            {
                dp[curlane][curpos] = dp[curlane][curpos + 1];
            }
            else
            {
                int ans = INT_MAX;
                for (int i = 1; i < 4; i++)
                {
                    if (curlane != i && obstacles[curpos] != i)
                    {
                        ans = min(ans, 1+dp[i][curpos+1]);
                    }
                }
                dp[curlane][curpos] = ans;
            }
        }
    }
    return min(dp[1][0]+1, min(dp[2][0], dp[3][0]+1));
}

// approach 3
int solution3(vector<int> &obstacles)
{
    int n=obstacles.size();
    vector<int>curr(4,1e9);
    vector<int>next(4,0);

    for (int curpos = n - 2; curpos >= 0; curpos--)
    {
        for (int curlane = 1; curlane <= 3; curlane++)
        {
            if (obstacles[curpos + 1] != curlane)
            {
                curr[curlane] = next[curlane];
            }
            else
            {
                int ans = INT_MAX;
                for (int i = 1; i < 4; i++)
                {
                    if (curlane != i && obstacles[curpos] != i)
                    {
                        ans = min(ans, 1+next[i]);
                    }
                }
                curr[curlane]= ans;
            }
        }
        next=curr;
    }
    return min(next[1]+1,min(next[2],next[3]+1));
}

int minSideJumps(vector<int> &obstacles)
{
    // for approach 1
    //  int n=obstacles.size();
    //  vector<vector<int>>dp(4,vector<int>(n,-1));
    //  return solution1(obstacles,dp,2,0,n-1);

    // for approach 2
    return solution2(obstacles);
    
    // for approach 3
    // return solution3(obstacles);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
