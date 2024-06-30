#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int kthLargest(vector<int> &Arr, int N, int K)
{
    priority_queue<long long,vector<long long>,greater<long long>>pq;
    for (int i = 0; i < N; i++)
    {
        long long int sum=0;
        for (int j = i; j < N; j++)
        {
            sum+=Arr[j];
            if (pq.size()<K)
            {
                pq.push(sum);
            }
            else{
                if (pq.top()<sum)
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}   

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
