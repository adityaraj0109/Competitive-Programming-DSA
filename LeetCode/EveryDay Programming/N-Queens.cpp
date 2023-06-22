#include <bits/stdc++.h>
#define ll long long
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solution(vector<vector<string>>&ans,vector<vector<string>>&board,int n){
    vector<string>temp;
    for (int i = 0; i < n; i++)
    {
        string str="";
        for (int j = 0; j < n; j++)
        {
            str+=board[i][j];
        }
        temp.push_back(str);
    }
    ans.push_back(temp);
}

bool isSafe(int row,int col,vector<vector<string>>&board, int n){
    int x=row;
    int y=col;
    //check for prev rows if there is any Q
    while (y>=0)
    {
        if (board[x][y]=="Q")
        {
            return false;
        }
        y--;
    }

    x=row;
    y=col;
    //check for prev diagonals if there is any Q
    while (x>=0 && y>=0)
    {
        if(board[x][y]=="Q"){
            return false;
        }
        x--;
        y--;
    }

    x=row;
    y=col;
    while (x<n && y>=0)
    {
        if(board[x][y]=="Q"){
            return false;
        }
        x++;
        y--;
    }
}

void solve(int col,vector<vector<string>>&ans,vector<vector<string>>&board, int n){
    if(col==n){
        solution(ans,board,n);
        return;
    }
    for (int row = 0; row < n; row++){
        if(isSafe(row,col,board,n)){
            board[row][col]="Q";
            solve(col+1,ans,board,n);
            board[row][col]=".";
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<vector<string>> board(n, vector<string>(n, "."));
    solve(0,ans,board,n);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
