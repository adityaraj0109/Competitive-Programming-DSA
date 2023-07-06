#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int minimumDays(int S, int N, int M)
{
    if(N<M) return -1;
    int sunday=S/7;
    int buyingDays=S-sunday;
    int totalfood=S*M;
    int ans=ceil(totalfood/(float)N);
    if(buyingDays<ans){
        return -1;
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
