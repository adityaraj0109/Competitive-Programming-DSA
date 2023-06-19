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

void segregateElements(int arr[], int n)
{
    vector<int>temp;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>=0){
            temp.push_back(arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<0){
            temp.push_back(arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]=temp[i];
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
