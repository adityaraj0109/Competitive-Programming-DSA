#include <bits/stdc++.h>
#define ll long long
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0;
    long long ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        ans = max(ans, sum);
        if (sum < 0)
        {
            sum = 0;
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
