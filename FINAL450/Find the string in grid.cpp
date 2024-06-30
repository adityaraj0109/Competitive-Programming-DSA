#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool dfs(vector<vector<char>> grid, string word, int index, int i, int j, int dir)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != word[index])
        return false;
    if (index == word.size()-1) return true;

    bool ans = false;
    if(dir==1) ans |= dfs(grid, word, index + 1, i - 1, j,1);
    if(dir==2) ans |= dfs(grid, word, index + 1, i - 1, j + 1,2);
    if(dir==3) ans |= dfs(grid, word, index + 1, i, j + 1,3);
    if(dir==4) ans |= dfs(grid, word, index + 1, i + 1, j + 1,4);
    if(dir==5) ans |= dfs(grid, word, index + 1, i + 1, j,5);
    if(dir==6) ans |= dfs(grid, word, index + 1, i + 1, j - 1,6);
    if(dir==7) ans |= dfs(grid, word, index + 1, i, j - 1,7);
    if(dir==8) ans |= dfs(grid, word, index + 1, i - 1, j - 1,8);
    return ans;
}

vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
{
    vector<vector<int>> ans;
    vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == word[0])
            {
                for (int dir = 1; dir <=8; dir++)
                {
                    if (dfs(grid, word, 0, i, j,dir))
                    {
                        ans.push_back({i, j});
                    }
                }
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
