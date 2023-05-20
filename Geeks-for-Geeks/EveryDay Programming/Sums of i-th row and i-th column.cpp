#include <bits/stdc++.h>
using namespace std;
int sumOfRowCol(int N, int M, vector<vector<int>> A)
{
    int m=min(N,M);
    int flag=0;
    int sum1,sum2,count=0;
    for (int i = 0; i < m; i++)
    {
        sum1=0,sum2=0;
        for (int j = 0; j < N; j++)
        {
            sum1+=A[j][i];
        }
        for (int k = 0; k < M; k++)
        {
            sum2+=A[i][k];
        }
        if (sum1==sum2)
        {
            count++;
        }
    }
    if (count==m)
    {
        flag=1;
        return flag;
    }
    return flag;
}
int main()
{
    vector<vector<int>> A;
    int N=4,M=1;
    A={{1},{2},{3},{4}};
    int ans=sumOfRowCol(N,M,A);
    cout<<ans;
    return 0;
}