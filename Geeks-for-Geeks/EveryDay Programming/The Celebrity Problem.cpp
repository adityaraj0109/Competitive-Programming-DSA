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

//Approach 1 
// int celebrity(vector<vector<int>> &M, int n)
// {
//     int value=M.size()-1;
//     for (int i = 0; i < M[0].size(); i++)
//     {
//         int count=0;
//         for (int j = 0; j <M.size(); j++)
//         {
//             if (M[j][i])
//             {
//                 count++;
//             }
//         }
//         if (count==value){
//             int c=0;
//             for (int k = 0; k < M[0].size(); k++)
//             {
//                 if (M[i][k]){
//                     c=1;
//                     break;
//                 }
//             }
//             if (!c){
//                 return i;
//             }
//         }
//     }
//     return -1;
// }

//Approach 2
int celebrity(vector<vector<int>> &M, int n)
{
    stack<int>s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size()>1)
    {
        int x=s.top();
        s.pop();
        int y=s.top();
        s.pop();
        if (M[x][y]){
            s.push(y);
        }
        else{
            s.push(x);
        }
    }
    int x=s.top();
    for (int i = 0; i < M[0].size(); i++)
    {
        if (M[x][i]){
            return -1;
        }
    }
    int count=0;
    for (int i = 0; i < M.size(); i++)
    {
        if (M[i][x]){
            count++;
        }
    }
    if (count==M.size()-1){
        return x;
    }
    else
    {
        return -1;
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
