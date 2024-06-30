#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    vector<int>ans;
    int top=0;
    int bottom=r-1;
    int left=0;
    int right=c-1;
    while (left<=right && top<=bottom)
    {
        for (int i = left; i <=right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <=bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for (int i = right; i >=left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
        }
        bottom--;
        if(left<=right){
            for (int i = bottom; i >=top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
        }
        left++;
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
