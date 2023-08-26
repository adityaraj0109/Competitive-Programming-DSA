#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int search(int A[], int l, int h, int key)
{
    while (h>=l)
    {
        int mid=(h+l)/2;
        if(A[mid]==key) return mid;
        if(A[l]<=A[mid]){
            if(key>=A[l] && key<A[mid]){
                h=mid-1;
            }
            else l=mid+1;
        }
        else{
            if(key>A[mid] && key<=A[h]){
                l=mid+1;
            }
            else h=mid-1;
        }
    }
    return -1;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
