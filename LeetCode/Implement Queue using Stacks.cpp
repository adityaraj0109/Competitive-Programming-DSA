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

//Approach 1 using O(N) complexity
// stack<int>s1;
// stack<int>s2;
// MyQueue() {
// }

// void push(int x) {
//     while (!s2.empty())
//     {
//         s1.push(s2.top());
//         s2.pop();
//     }
//     s1.push(x);
//     while (!s1.empty())
//     {
//         s2.push(s1.top());
//         s1.pop();
//     }
// }

// int pop() {
//     int y=s2.top();
//     s2.pop();
//     return y;
// }

// int peek() {
//     return s2.top();
// }

// bool empty() {
//     if (s2.empty())
//     {
//         return true;
//     }
//     return false;
// }


//Approach 2 using O(1) complexity
stack<int>input;
stack<int>output;
MyQueue() {
}

void push(int x) {
    input.push(x);
}

int pop() {
    if (!output.empty())
    {
        int y=output.top();
        output.pop();
        return y;
    }
    while (!input.empty())
    {
        output.push(input.top());
        input.pop();
    }
    int y=output.top();
    output.pop();
    return y;
}

int peek() {
    if (!output.empty())
    {
        return output.top();
    }
    while (!input.empty())
    {
        output.push(input.top());
        input.pop();
    }
    return output.top();
}

bool empty() {
    if (output.empty() && input.empty())
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
