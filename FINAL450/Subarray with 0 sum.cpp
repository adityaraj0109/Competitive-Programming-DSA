#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool subArrayExists(int arr[], int n)
{
    unordered_map<int,int>m;
    int sum=0;
    m[sum]++;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        if(m[sum]!=0){
            return true;
        }
        m[sum]++;
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
