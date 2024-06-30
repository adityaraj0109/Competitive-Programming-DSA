#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int ans=-1,row=0,col=m-1;
    while (col>=0 && row<n)
    {
        if(arr[row][col]==0){
            row++;
        }
        else{
            col--;
            ans=row;
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
