#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

priority_queue<int>maxheap;
priority_queue<int,vector<int>,greater<int>>minheap;
double median=-1;
MedianFinder()
{
}

void addNum(int num)
{
    if (maxheap.size()==minheap.size())
    {
        if (num>median){
            minheap.push(num);
            median=minheap.top();
        }
        else{
            maxheap.push(num);
            median=maxheap.top();
        }
    }
    else if (maxheap.size()>minheap.size())
    {
        if (num>median){
            minheap.push(num);
            median=(minheap.top()+maxheap.top())/2.0;
        }
        else{
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(num);
            median=(minheap.top()+maxheap.top())/2.0;
        }
    }
    else{
        if (num>median){
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(num);
            median=(minheap.top()+maxheap.top())/2.0;
        }
        else{
            maxheap.push(num);
            median=(minheap.top()+maxheap.top())/2.0;
        }
    }
}

double findMedian()
{
    return median;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
