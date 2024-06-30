#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int transform (string A, string B)
{
    if(A.size()!=B.size()) return -1;
    unordered_map<char,int>m;
    for (int i = 0; i < A.size(); i++)
    {
        m[A[i]]++;
        m[B[i]]--;
    }
    for (auto it:m)
    {
        if(it.second!=0){
            return -1;
        }
    }
    int i=A.size()-1,j=B.size()-1;
    int ans=0;
    while (i>=0 && j>=0)
    {
        if(A[i]==B[j]){
            i--;
            j--;
        }
        else{
            while (i>=0 && A[i]!=B[j])
            {
                ans++;
                i--;
            }
            i--;
            j--;
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
