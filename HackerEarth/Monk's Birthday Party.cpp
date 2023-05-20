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
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        set<string>s;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin>>str;
            s.insert(str);
        }
        for(auto &it:s){
            cout<<it<<endl;
        }
    }
    return 0;
}
