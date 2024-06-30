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

void insertAtLast(stack<int> &St,int x){
    if (St.empty())
    {
        St.push(x);
        return;
    }
    int y=St.top();
    St.pop();

    insertAtLast(St,x);
    St.push(y);
} 

void Reverse(stack<int> &St)
{
    if (St.empty())
    {
        return;
    }
    
    int x=St.top();
    St.pop();
    Reverse(St);
    insertAtLast(St,x);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
