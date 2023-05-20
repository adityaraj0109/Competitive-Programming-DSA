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
        int n;
        cin>>n;
        int k,f;
        cin>>k>>f;
        vector<pair<int,int>>v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i].first>>v[i].second;
            v[i].first=k-v[i].first;
        }
        sort(v.begin(),v.end());
        int count=0,j=0;
        multiset<int>m;
        bool reached=true;
        for (int i = 1; i < k; i++)
        {
            f--;
            if (v[j].first==i)
            {
                m.insert(v[j].second);
                j++;
            }
            if (f==0)
            {
                if (m.empty())
                {
                    reached=false;
                    break;
                }
                else
                {
                    auto it=--m.end();
                    f+=(*it);
                    m.erase(it);
                    count++;
                }
            }
        }
        if (reached)
        {
            cout<<count<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}
