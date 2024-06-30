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

int alternateDigitSum(int n)
{
    int sum=0;
    string str=to_string(n);
    for (int i = 0; i < str.length(); i++)
    {
        if (i%2==0)
        {
            sum+=(str[i]-'0');
        }
        else{
            sum-=(str[i]-'0');
        }
    }
    return sum;
}

int main()
{
    debugMode();
    int ans=alternateDigitSum(521);
    cout << ans << endl;
    return 0;
}
