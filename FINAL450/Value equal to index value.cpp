#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> valueEqualToIndex(int arr[], int n)
{
    vector<int>ans;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==i+1){
            ans.push_back(arr[i]);
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
