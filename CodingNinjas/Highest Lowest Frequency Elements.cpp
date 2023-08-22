#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> getFrequencies(vector<int>& v) {
    unordered_map<int,int>freq;
    for (int i = 0; i < v.size(); i++)
    {
        freq[v[i]]++;
    }
    vector<int>ans;
    pair<int,int>maxx={INT_MAX,INT_MIN};
    pair<int,int>minn={INT_MAX,INT_MAX};
    for(auto it:freq){
        if(it.second>=maxx.second){
            if((it.second==maxx.second && it.first<maxx.first) || it.second>maxx.second){
                maxx={it.first,it.second};
            }
        }
        if(it.second<=minn.second){
            if((it.second==minn.second && it.first<minn.first) || (it.second<minn.second)){
                minn={it.first,it.second};
            }
        }
    }
    ans.push_back(maxx.first);
    ans.push_back(minn.first);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
