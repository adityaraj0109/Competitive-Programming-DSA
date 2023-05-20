#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        vector<long long int>v(n);
        for (long long int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long int gcdd;
        gcdd=__gcd(v[0],v[1]);
        for (long long int i = 2; i < n; i++)
        {
            gcdd=__gcd(gcdd,v[i]);
        }
        cout << gcdd*n << endl;
    }
    return 0;
}