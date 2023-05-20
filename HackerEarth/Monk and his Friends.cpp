#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        long long int a;
        unordered_set<long long int>mp;
        for (int i = 0; i <n ; i++)
        {
            cin>>a;
            mp.insert(a);
        }
        for (int i = 0; i <m ; i++)
        {
            cin>>a;
            if (mp.count(a))
            {
                cout<<"YES"<<endl;
            }
            else{
              mp.insert(a);
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}