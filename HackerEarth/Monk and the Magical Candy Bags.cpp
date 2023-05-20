#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        long long int a;
        multiset<long long int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            m.insert(a);
        }
        long long int sum=0;
        for (int i = 0; i < k; i++)
        {
          auto it=--m.end();
            sum+=(*it);
            m.insert((*it)/2);
            m.erase(it);
        }
        cout<<sum<<endl;
    }
    return 0;
}