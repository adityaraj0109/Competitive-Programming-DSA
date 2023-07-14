#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low=mat[0][0];
    int high=mat[n-1][n-1];
    while(low<=high){
        int mid=(low+high)/2;
        int count=0;
        for (int i = 0; i < n; i++)
        {
            int l=0,h=n-1;
            while (l<=h)
            {
                int m=(l+h)/2;
                if(mat[i][m]<=mid) l=m+1;
                else h=m-1;
            }
            count+=l;
        }
        if(count<k) low=mid+1;
        else high=mid-1; 
    }
    return low;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
