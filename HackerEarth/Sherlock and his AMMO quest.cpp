#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

bool cmp(pair<int,string>a,pair<int,string>b){
    if (a.first==b.first)
    {
        return a<b;
    }
    return a>b;
}

int main()
{
    int n,x;
    cin>>n;
    string s;
    vector<pair<int,string>>vec;
    for (int i = 0; i < n; i++)
    {
        cin>>s>>x;
        vec.push_back({x,s});
    }
    sort(vec.begin(),vec.end(),cmp);
    for (int i = 0; i < n; i++)
    {
        cout<<vec[i].second<<" "<<vec[i].first<<endl;
    }
    return 0;
}