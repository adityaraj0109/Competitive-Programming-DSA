#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if(intervals.size()==1){
        return intervals;
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int i = 0;
    while (i < intervals.size() - 1)
    {
        if (intervals[i][1] >= intervals[i + 1][0])
        {
            int start=intervals[i][0];
            int end=intervals[i][1];
            while (i<intervals.size() - 1 && end >= intervals[i + 1][0])
            {
                end=max(intervals[i+1][1],end);
                i++;
            }
            i++;
            ans.push_back({start,end});
        }
        else{
            int start=intervals[i][0];
            int end=intervals[i][1];
            i++;
            ans.push_back({start,end});
        }
    }
    if(ans[ans.size()-1][1]<intervals[intervals.size()-1][1]){
        ans.push_back({intervals[intervals.size()-1][0],intervals[intervals.size()-1][1]});
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
