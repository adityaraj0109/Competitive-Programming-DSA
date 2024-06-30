#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

long long maxProduct(vector<int> arr, int n)
{
    long long ans=LONG_LONG_MIN;
    long long front=1;
    long long back=1;
    for(int i=0;i<n;i++){
        if(front==0) front=1;
        if(back==0) back=1;
        front=front*arr[i];
        back=back*arr[n-i-1];
        ans=max(ans,max(front,back));
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
