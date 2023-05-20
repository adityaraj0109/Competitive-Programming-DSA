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

int matrix[17][50001];

TreeAncestor(int n, vector<int> &parent)
{
    for (int i = 0; i < n; i++)
    {
        matrix[0][i]=parent[i];
    }
    for (int i = 1; i < 17; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int col=matrix[i-1][j];
            if (col==-1)
            {
                matrix[i][j]=-1;
            }
            else{
                matrix[i][j]=matrix[i-1][col];
            }
        }
    } 
}

int getKthAncestor(int node, int k)
{
    int temp=node;
    for (int i = 16; i>=0; i--)
    {
        if (1<<i & k){
            if(temp==-1){
                return -1;
            }
            temp=matrix[i][temp];
        }
    }
    return temp;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
