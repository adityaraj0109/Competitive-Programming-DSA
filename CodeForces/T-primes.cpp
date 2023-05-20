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

int main()
{
    debugMode();
    int num=1e6+10;
    int n;
    cin >> n;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<bool>prime(num,1);
    prime[0]=prime[1]=false;
    for (int i = 2; i < num; i++)
    {
        if (prime[i])
        {
            for (int j = i*2; j < num; j=j+i)
            {
                prime[j]=false;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        long long int sq=sqrt(v[i]);
        long long int mul=sq*sq;
        if (prime[sq] && mul==v[i])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
