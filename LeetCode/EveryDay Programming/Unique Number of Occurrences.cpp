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

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_set<int>s;
    sort(arr.begin(),arr.end());
    int countt=1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i]!=arr[i-1])
        {
            if (s.count(countt))
            {
                return false;
            }
            s.insert(countt);
            countt=1;
        }
        else{
            countt++;
        }
        if (i==arr.size()-1)
        {
            if (s.count(countt))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    debugMode();
    vector<int>v={-3,0,1,-3,1,1,1,-3,10,0};
    int ans = uniqueOccurrences(v);
    cout <<ans << endl;
    return 0;
}
