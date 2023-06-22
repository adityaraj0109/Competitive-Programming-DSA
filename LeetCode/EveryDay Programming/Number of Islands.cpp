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

void dfs(vector<vector<char>> &grid, int i, int j)
{
    int m=grid.size();
    int n=grid[0].size();
    if(i<0 || j<0) return;
    if(i>=m || j>=n) return;
    if(grid[i][j]!='1') return;

    grid[i][j]='0';

    dfs(grid,i-1,j);
    dfs(grid,i+1,j);
    dfs(grid,i,j-1);
    dfs(grid,i,j+1);
}

int numIslands(vector<vector<char>> &grid)
{
    int count=0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j]=='1'){
                dfs(grid,i,j);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    debugMode();
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},{'1', '1', '0', '1', '0'},{'1', '1', '0', '0', '0'},{'0', '0', '0', '0', '0'}};
    int ans = numIslands(grid);
    cout << ans << endl;
    return 0;
}
