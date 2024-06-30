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

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    vector<long long>ans;
    deque<long long int>dq;     
    for (long long int i = 0; i < K; i++)
    {
        if (A[i]<0)
        {
            dq.push_back(i);
        }
    }
    if (dq.size()>0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    for (long long int i = K; i < N; i++)
    {
        if (!dq.empty() && i-dq.front() >=K)
        {
            dq.pop_front();
        }
        if (A[i]<0)
        {
            dq.push_back(i);
        }
        if (dq.size()>0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
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
