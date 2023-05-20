// solution taken from leetcode question fill flood
#include <bits/stdc++.h>
using namespace std;

void dfs(int i,int j, int color,vector<vector<int>> &image, int initial_color)
{
    int n=image.size();
    int m=image[0].size();
    if (i<0 || j<0) return;
    if(i>=n || j>=m) return;
    if(image[i][j]!=initial_color) return;

    image[i][j]=color;

    dfs(i-1,j,color,image,initial_color);
    dfs(i,j-1,color,image,initial_color);
    dfs(i+1,j,color,image,initial_color);
    dfs(i,j+1,color,image,initial_color);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initial_color=image[sr][sc];
    if (initial_color!=color)
    {
        dfs(sr,sc,color,image, initial_color);
    }
    return image;
}

int main()
{
    int sr=1,sc=1,color=2;
    vector<vector<int>>vec={{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>>ans=floodFill(vec,sr,sc,color);
    for(auto it:ans){
        for(int i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}