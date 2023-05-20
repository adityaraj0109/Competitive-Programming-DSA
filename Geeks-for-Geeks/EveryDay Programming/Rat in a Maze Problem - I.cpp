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

bool safe(vector<vector<int>> &m, int n, vector<vector<int>>&visited,int x, int y){
    return x>=0 && x<n && y>=0 && y<n && visited[x][y]==0 && m[x][y]==1 ;
}

void solution(vector<vector<int>> &m, int n, vector<string>&ans,vector<vector<int>>&visited,int x, int y,string str){
    if(x==n-1 && y==n-1){
        ans.push_back(str);
        return;
    }
    visited[x][y]=1;
    int newx=x-1;
    int newy=y;
    if (safe(m,n,visited,newx,newy))
    {
        str.push_back('U');
        solution(m,n,ans,visited,newx,newy,str);
        str.pop_back();
    }
    newx=x;
    newy=y+1;
    if (safe(m,n,visited,newx,newy))
    {
        str.push_back('R');
        solution(m,n,ans,visited,newx,newy,str);
        str.pop_back();
    }
    newx=x+1;
    newy=y;
    if (safe(m,n,visited,newx,newy))
    {
        str.push_back('D');
        solution(m,n,ans,visited,newx,newy,str);
        str.pop_back();
    }
    newx=x;
    newy=y-1;
    if (safe(m,n,visited,newx,newy))
    {
        str.push_back('L');
        solution(m,n,ans,visited,newx,newy,str);
        str.pop_back();
    }
    visited[x][y]=0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string>ans;
    if (m[0][0]==0)
    {
        return ans;
    }
    vector<vector<int>>visisted=m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visisted[i][j]=0;
        }
    }
    string str="";
    solution(m,n,ans,visisted,0,0,str);
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
