#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int median(vector<vector<int>> &matrix, int R, int C)
{
    int start=0,end=2000;
    int n=R*C;
    while (start<=end)
    {
        int mid=(start+end)/2;
        int ans=0;
        for (int i=0;i<R;i++){
            int low=0,high=C-1;
            while (low<=high)
            {
                int m=(low+high)/2;
                if(matrix[i][m]<=mid) low=m+1;
                else high=m-1;
            }
            ans+=low;
        }
        if(ans<=n/2) start=mid+1;
        else end=mid-1;
    }
    return start;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
