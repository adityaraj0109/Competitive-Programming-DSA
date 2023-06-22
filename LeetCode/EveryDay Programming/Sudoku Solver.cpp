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

bool isSafe(int row, int col,vector<vector<char>> &board, char ch){
    int n=board[0].size();
    for(int i=0;i<n;i++){
        if(board[row][i]==ch) return false;
        if(board[i][col]==ch) return false;
        if (board[3*(row/3)+i/3][3*(col/3)+i%3]==ch)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>> &board){
    int n=board[0].size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if(board[row][col]=='.'){
                for (char ch = '1'; ch <='9'; ch++)
                {
                    if(isSafe(row,col,board,ch)){
                        board[row][col]=ch;
                        bool canProceed=solve(board);
                        if(canProceed){
                            return true;
                        }
                        board[row][col]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
