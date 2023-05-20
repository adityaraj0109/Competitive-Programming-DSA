#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
    string str;
    cin>>str;
    unordered_map<char,int>m;
    for (int i = 0; i < str.size(); i++)
    {
        m[str[i]]++;
    }
    int max=0;
    set<char>s;
    for (auto it: m)
    {
        if (max<it.second)
        {
            max=it.second;
        }
    }
    for (auto it: m)
    {
        if (it.second==max)
        {
            s.insert(it.first);
        }
    }
    auto it=s.begin();
    cout<<*it<<endl;
    return 0;
}