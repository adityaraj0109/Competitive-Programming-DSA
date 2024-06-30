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

int m = 1e9 + 7;

int binary(long long int a, long long int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return ans;
}

int monkeyMove(int n)
{
    int deno = binary(2, n);
    int answer=(deno-2)%m;
    if (answer<0)
    {
        answer+=m;
    }
    return answer;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<monkeyMove(500000003)<<endl;
    return 0;
}
