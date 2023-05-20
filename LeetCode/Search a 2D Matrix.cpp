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

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m=matrix.size();
    int n=matrix[0].size();
    int high=(m*n)-1,low=0;
    while (high>=low)
    {
        int mid=(high+low)/2;
        int element=matrix[mid/n][mid%n];
        if (element==target)
        {
            return true;
        }
        else if (element>target)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return false;
}

int main()
{
    debugMode();
    vector<vector<int>> matrix = {{1},{3}};
    int target = 3;
    bool ans=searchMatrix(matrix,target);
    cout<<ans<<endl;
    return 0;
}
