#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string rearrangeString(string str)
{
    unordered_map<char,int>m;
    for (int i = 0; i < str.size(); i++)
    {
        m[str[i]]++;
        if(m[str[i]]>(str.size()+1)/2) return "-1";
    }
    priority_queue<pair<int,char>>pq;
    for(auto it:m){
        pq.push({it.second,it.first});
    }
    string ans="";
    while(pq.size()>=2){
        pair<int,char>p1=pq.top();
        pq.pop();
        pair<int,char>p2=pq.top();
        pq.pop();
        ans+=p1.second;
        ans+=p2.second;
        if(p1.first-1>0){
            pq.push({p1.first-1,p1.second});
        }
        if(p2.first-1>0){
            pq.push({p2.first-1,p2.second});
        }
    }
    while (!pq.empty())
    {
        pair<int,char>p1=pq.top();
        pq.pop();
        ans+=p1.second;
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
