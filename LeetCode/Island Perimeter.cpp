#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void dfs(vector<vector<int>> &grid, int &ans, int i, int j){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
        ans++;
        return;
    }
    if(grid[i][j]==0){
        ans++;
        return;
    }
    if(grid[i][j]==-1) return;

    grid[i][j]=-1;

    dfs(grid,ans,i-1,j);
    dfs(grid,ans,i,j+1);
    dfs(grid,ans,i+1,j);
    dfs(grid,ans,i,j-1);
}

int islandPerimeter(vector<vector<int>> &grid)
{
    int ans=0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if(grid[i][j]){
                dfs(grid,ans,i,j);
                break;
            }
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
