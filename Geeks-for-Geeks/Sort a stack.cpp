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

void insertSorted(stack<int>&s,int x){
    if (s.empty())
    {
        s.push(x);
        return;
    }
    if (s.top() < x){
        s.push(x);
        return;
    }
    int t = s.top();
    s.pop();
    insertSorted(s,x);
    s.push(t);
}

void solution(stack<int>&s){
    if (s.empty())
    {
        return;
    }
    int x=s.top();
    s.pop();
    solution(s);
    insertSorted(s,x);
}

void SortedStack :: sort()
{
    solution(s);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
