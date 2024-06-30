#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class compare{
    public:
        bool operator()(pair<int,int> a, pair<int,int>b){
            return a.second<b.second;
        }
};

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int,int>>pairs;
    for (int i = 0; i < n; i++)
    {
        pairs.push_back({start[i],end[i]});
    }
    sort(pairs.begin(),pairs.end(),compare());
    int count=1;
    int temp=pairs[0].second;
    for (int i = 1; i < n; i++)
    {
        if(pairs[i].first>temp){
            count++;
            temp=pairs[i].second;
        }
    }
    return count;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
