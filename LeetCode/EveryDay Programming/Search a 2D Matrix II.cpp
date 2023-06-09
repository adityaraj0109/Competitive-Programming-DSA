#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int col = m - 1, row = 0;
    while (col >= 0 && row < n)
    {
        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return false;
}

int main()
{
    
    return 0;
}