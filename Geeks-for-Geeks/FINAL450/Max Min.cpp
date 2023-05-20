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

int findSum(int A[], int N)
{
    int min=INT_MAX;
    int max=INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if (min>A[i])
        {
            min=A[i];
        }
        if (max<A[i])
        {
            max=A[i];
        }
    }
    return min+max;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
