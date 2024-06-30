#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void dfs(vector<vector<char>> &mat, string target, int index, int i, int j, int &ans)
{
    if (i >= 0 && j >= 0 && i < mat.size() && j < mat[0].size() && mat[i][j] == target[index]){
        mat[i][j] = '#';
        if (index == target.size()-1){
            ans++;
        }
        else{
            dfs(mat, target, index + 1, i - 1, j,ans);
            dfs(mat, target, index + 1, i, j + 1,ans);
            dfs(mat, target, index + 1, i + 1, j,ans);
            dfs(mat, target, index + 1, i, j - 1,ans);
        }
        mat[i][j] = target[index];
    }
}

int findOccurrence(vector<vector<char>> &mat, string target)
{
    int ans=0;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == target[0])
            {
                dfs(mat,target,0,i,j,ans);
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
