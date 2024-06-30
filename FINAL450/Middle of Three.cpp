#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int middle(int A, int B, int C)
{
    int mini=min(A,min(B,C));
    int maxi=max(A,max(B,C));
    if(A!=mini && A!=maxi) return A;
    if(B!=mini && B!=maxi) return B;
    return C;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
