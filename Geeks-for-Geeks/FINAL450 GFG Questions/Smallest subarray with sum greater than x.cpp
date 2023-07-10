#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int smallestSubWithSum(int arr[], int n, int x)
{
    int sum = arr[0];
    int ans=INT_MAX;
    int j=0,i=0;
    while (j<n)
    {
        if(sum>x){
            int length=j-i+1;
            ans=min(ans,length);
            sum=sum-arr[i];
            i++;
        }
        else{
            j++;
            if(j!=n) sum+=arr[j];
        }
    }
    if(ans==INT_MAX){
        return 0;
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
