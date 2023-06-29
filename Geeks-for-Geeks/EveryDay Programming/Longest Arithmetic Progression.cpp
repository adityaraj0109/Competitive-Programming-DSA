#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int lengthOfLongestAP(int A[], int n)
{
    if(n<=2) return n;
    int ans=0;
    unordered_map<int,int>dp;
    for (int i = 0; i < n; i++)
    {
        dp[A[i]]++;
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int d=A[j]-A[i];
            int count=2;
            int a=A[j];
            while (dp.find(a+d)!=dp.end())
            {
                count++;
                a=a+d;
            }
            ans=max(ans,count);
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
