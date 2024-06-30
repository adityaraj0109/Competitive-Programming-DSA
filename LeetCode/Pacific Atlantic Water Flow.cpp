#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solution(vector<vector<int>> &heights,vector<vector<int>> &matrix, int parent, int i,int j){
    if(i<0 || j<0) return;
    if(i>=heights.size() || j>=heights[0].size()) return;
    if(matrix[i][j]) return;
    if(heights[i][j]<parent) return;

    matrix[i][j]=1;

    solution(heights,matrix,heights[i][j],i-1,j);
    solution(heights,matrix,heights[i][j],i,j+1);
    solution(heights,matrix,heights[i][j],i+1,j);
    solution(heights,matrix,heights[i][j],i,j-1);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    vector<vector<int>>ans;
    if(heights.size()==0) return ans;
    int n=heights.size();
    int m=heights[0].size();
    vector<vector<int>>pacific(n,vector<int>(m,0));
    vector<vector<int>>atlantic(n,vector<int>(m,0));
    for (int i = 0; i < n; i++)
    {
        solution(heights,pacific,INT_MIN,i,0);
    }
    for (int j = 0; j < m; j++)
    {
        solution(heights,pacific,INT_MIN,0,j);
    }
    for (int i = 0; i < n; i++)
    {
        solution(heights,atlantic,INT_MIN,i,m-1);
    }
    for (int j = 0; j < m; j++)
    {
        solution(heights,atlantic,INT_MIN,n-1,j);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(pacific[i][j] && atlantic[i][j]){
                ans.push_back({i,j});
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
