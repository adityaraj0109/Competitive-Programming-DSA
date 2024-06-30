#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> nextPermutation(int N, vector<int> arr)
{
    int i;
    for (i = N-2; i >=0; i--)
    {
        if(arr[i]<arr[i+1]) break;
    }
    if(i<0) reverse(arr.begin(),arr.end());
    else{
        for (int j = N-1; j>=0; j--)
        {
            if(arr[j]>arr[i]){
                swap(arr[j],arr[i]);
                break;
            }
        }
        reverse(arr.begin()+i+1,arr.end());
    }
    return arr;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
