#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

long long countTriplets(long long arr[], int n, long long sum)
{
    long long count=0;
    sort(arr,arr+n);
    for (int i = 0; i < n; i++)
    {
        int target=sum-arr[i];
        int high=n-1,low=i+1;
        while (high>low)
        {
            int add=arr[high]+arr[low];
            if(target>add){
                count+=high-low;
                low++;
            }
            else{
                high--;
            }
        }
    }
    return count;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
