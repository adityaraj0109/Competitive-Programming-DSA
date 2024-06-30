#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    unordered_set<char>s1;
    unordered_set<char>s2;
    unordered_set<char>s3;
    int count1=0,count2=0,count3=0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j <9 ; j++)
        {
            if (board[i][j]!='.')
            {
                count1++;
                s1.insert(board[i][j]);
            }
            if (board[j][i]!='.')
            {
                count2++;
                s2.insert(board[j][i]);
            }
        }
        if (s1.size()!=count1)
        {
            return false;
        }
        if (s2.size()!=count2)
        {
            return false;
        }
        count1=0;
        count2=0;
        s1.clear();
        s2.clear();
    }
    count1=0,count2=0;
    s1.clear();
    s2.clear();
    int m=0,n=3;
    for (int i = m; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j]!='.')
            {
                count1++;
                s1.insert(board[i][j]);
            }
        }
        for (int j = 3; j <6 ; j++)
        {
            if (board[i][j]!='.')
            {
                count2++;
                s2.insert(board[i][j]);
            }
        }
        for (int j = 6; j < 9; j++)
        {
            if (board[i][j]!='.')
            {
                count3++;
                s3.insert(board[i][j]);
            }
        }
        if (i==2 || i==5)
        {
            if (s1.size()!=count1 || s2.size()!=count2 || s3.size()!=count3)
            {
                return false;
            }
            m=m+3;
            n=n+3;
            s1.clear();
            s2.clear();
            s3.clear();
            count1=0;
            count2=0;
            count3=0;
        }
        if (i==8)
        {
            if (s1.size()!=count1 || s2.size()!=count2 || s3.size()!=count3)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>>vec;
    vec={{'.','.','.','.','.','.','5','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'9','3','.','.','2','.','4','.','.'},
        {'.','.','7','.','.','.','3','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','3','4','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','.'},
        {'.','.','.','.','.','5','2','.','.'}};
    bool ans=isValidSudoku(vec);
    cout<<ans<<endl;
    return 0;
}