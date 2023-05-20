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

vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
{
    int m=score.size();
    int n=score[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m-1; j++)
        {
            if(score[j][k]<score[j+1][k]){
                swap(score[j],score[j+1]);
            }
        }
    }
    return score;
}

int main()
{
    debugMode();
    return 0;
}
