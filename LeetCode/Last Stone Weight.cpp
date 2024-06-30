#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int>pq;
    for(auto it:stones) pq.push(it);
    while (pq.size()>1)
    {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        int diff=a-b;
        if(diff>0) pq.push(diff);
    }
    return  pq.empty()?0 : pq.top();
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
