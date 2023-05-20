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
    int a=2147483647;
    int b=-2147483648;
    string s=to_string(x);
    std::reverse(s.begin(),s.end());
    long long int n=stoll(s);
    if (x<0)
    {
        n=-n;
    }
    if (n>a || n<b)
    {
        return 0;
    }
    x=n;
    return x;
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
