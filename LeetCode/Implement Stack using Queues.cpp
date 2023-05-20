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

//Approach 1 using two queues 
// queue<int>q1;
// queue<int>q2;
// MyStack()
// {
// }

// void push(int x)
// {
//     q2.push(x);
//     while (!q1.empty())
//     {
//         q2.push(q1.front());
//         q1.pop();
//     }
//     while (!q2.empty())
//     {
//         q1.push(q2.front());
//     }
// }

// int pop()
// {
//     int data=q1.front();
//     q1.pop();
//     return data;
// }

// int top()
// {
//     return q1.front();
// }

// bool empty()
// {
//     if (q1.empty())
//     {
//         return true;
//     }
//     return false;
// }

//Approach 2 using only one queue
queue<int>q;
MyStack()
{
}

void push(int x)
{
    q.push(x);
    for (int i = 0; i < q.size()-1; i++)
    {
        int y=q.front();
        q.pop();
        q.push(y);
    }
}

int pop()
{
    int data=q.front();
    q.pop();
    return data;
}

int top()
{
    return q.front();
}

bool empty()
{
    if (q.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
