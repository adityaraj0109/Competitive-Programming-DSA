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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        vector<int>fgcd(n),bgcd(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        fgcd[0]=v[0];
        bgcd[n-1]=v[n-1];
        for (int i = 1; i < n; i++)
        {
            fgcd[i]=__gcd(fgcd[i-1],v[i]);
        }
        for (int i = n-2; i >=0; i--)
        {
            bgcd[i]=__gcd(bgcd[i+1],v[i]);
        }
        for (int i = 0; i < q; i++)
        {
            int l,r;
            cin>>l>>r;
            l--,r--;
            if (l==0)
            {
                cout<<bgcd[r+1]<<endl;
            }
            else if (r==n-1)
            {
                cout<<fgcd[l-1]<<endl;
            }
            else{
                cout<<__gcd(fgcd[l-1],bgcd[r+1])<<endl;
            }
        }
    }
    return 0;
}
