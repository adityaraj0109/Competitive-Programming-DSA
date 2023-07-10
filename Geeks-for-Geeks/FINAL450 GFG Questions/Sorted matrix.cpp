#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
{
    vector<int>matrix;
    for(auto it:Mat){
        for(int val:it){
            matrix.push_back(val);
        }
    }
    sort(matrix.begin(),matrix.end());
    int k=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Mat[i][j]=matrix[k++];
        }
    }
    return Mat;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
