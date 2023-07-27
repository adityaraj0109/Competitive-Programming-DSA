#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool findPair(int arr[], int size, int n){
    sort(arr,arr+size,greater<int>());
    for (int i = 0; i < size; i++)
    {
        int target=arr[i]-n;
        int high=size-1,low=i+1;
        while (low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid]>target){
                low=mid+1;
            }
            else high=mid-1;
        }
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
