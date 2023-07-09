#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class compare
{
public:
    bool operator()(Job a, Job b)
    {
        return a.profit > b.profit;
    }
};

vector<int> JobScheduling(Job arr[], int n)
{
    vector<int> ans;
    sort(arr, arr + n, compare());
    int count=0;
    int maxprofit=0;
    int maxdeadline=INT_MIN;
    for (int i = 0; i <n ; i++)
    {
        maxdeadline=max(maxdeadline,arr[i].dead);
    }
    vector<int>schedule(maxdeadline+1,-1);
    for (int i = 0; i < n; i++)
    {
        int currid=arr[i].id;
        int currdeadline=arr[i].dead;
        int currprofit=arr[i].profit;
        for (int j = currdeadline; j >0; j--)
        {
            if(schedule[j]==-1){
                schedule[j]=currid;
                count++;
                maxprofit=maxprofit+currprofit;
                break;
            }
        }
    }
    ans.push_back(count);
    ans.push_back(maxprofit);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
