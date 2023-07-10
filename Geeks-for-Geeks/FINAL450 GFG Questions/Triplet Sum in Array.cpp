#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool find3Numbers(int A[], int n, int X)
{
    sort(A,A+n);
    for (int i = 0; i < n-2; i++)
    {
        int high=n-1;
        int low=i+1;
        int target=X-A[i];
        while (high>low)
        {
            int sum=A[high]+A[low];
            if(sum==target){
                return true;
            }
            else if(sum>target){
                high--;
            }
            else{
                low++;
            }
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
