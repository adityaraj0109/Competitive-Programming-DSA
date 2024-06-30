#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int reverse(int x)
{
    int a=INT_MIN;
    int b=INT_MAX;
    int ans=0;
    while (x != 0) {
        int rem=x%10;
        x=x/10;
        if ((ans<a/10) || (ans>b/10)) return 0;
        ans=ans*10+rem;
    }
    return ans;
}

int main()
{
    debugMode();
    int n;
    cin >> n;
    int ans = reverse(n);
    cout << ans << endl;
    return 0;
}
