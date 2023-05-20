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

stack<long long int>s;
int mini;
MinStack()
{
}
void push(int val)
{
    if (s.empty())
    {
        s.push(val);
        mini=val;
    }
    else{
        if(val<mini){
            long long int i=2*1LL*val-mini;
            s.push(i);
            mini=val;
        }
        else{
            s.push(val);
        }
    }
}

void pop()
{
    long long int curr=s.top();
    s.pop();
    if(curr<mini){
        long long int prevMin=mini;
        long long int val=2*1LL*mini-curr;
        mini=val;
    }
}

int top()
{
    if (s.top()<mini)
    {
        return mini;
    }
    return s.top();
}

int getMin()
{
    return mini;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
