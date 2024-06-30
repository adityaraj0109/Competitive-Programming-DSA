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

bool search(vector<vector<int>> matrix, int n, int m, int x)
{
    int j=m-1;
    int i=0;
    while(i<n && j>=0){
        if(matrix[i][j]==x){
            return true;
        }
        else if(matrix[i][j]<x){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
