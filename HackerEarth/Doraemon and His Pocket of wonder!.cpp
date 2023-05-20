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
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        map<int,int>mp;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin>>a;
            mp[a]++;
        }
        cin>>m;
        vector<int>vec(m);
        for (int i = 0; i < m; i++)
        {
            cin>>vec[i];
        }
        for (int i = 0; i < m; i++)
        {
            if (mp.count(vec[i]))
            {
                auto ptr=mp.find(vec[i]);
                int b=ptr->second;
                while (b--)
                {
                    cout<<vec[i]<<" ";
                    mp[vec[i]]--;
                }
            }
        }
        for (auto it:mp)
        {
            while (it.second--)
            {
                cout<<it.first<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
