#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &queries)
{
    unordered_map<int,pair<int,int>>m;
    vector<vector<int>>ans;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='0' && m.find(0)==m.end()){
            m[0]={i,i};
        }
        if(s[i]=='1'){
            int j=i+1;
            if(m.find(1)==m.end()){
                m[1]={i,i};
            }
            int value=1;
            while (j<s.size() && (j-i+1)<31)
            {
                if(s[j]=='0'){
                    value=value*2;
                }
                else{
                    value=value*2+1;
                }
                if(m.find(value)==m.end()){
                    m[value]={i,j};
                }
                j++;
            }
        }
    }
    for (auto query:queries){
        int value=query[0]^query[1];
        if(m.find(value)!=m.end()){
            ans.push_back({m[value].first,m[value].second});
        }
        else{
            ans.push_back({-1,-1});
        }
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
