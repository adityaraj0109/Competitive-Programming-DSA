#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int>find(int arr[],int n, int x){
    if(arr[n-1]<x) return {-1,-1};
    vector<int>ans;
    int pos=lower_bound(arr,arr+n,x)-&arr[0];
    if(arr[pos]!=x) return {-1,-1};
    ans.push_back(pos);
    pos=upper_bound(arr,arr+n,x)-&arr[1];
    if(arr[pos]!=x) return {-1,-1};
    ans.push_back(pos);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
