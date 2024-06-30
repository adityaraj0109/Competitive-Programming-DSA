#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool ispar(string x)
{
    stack<int>s;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '(' || x[i] == '{' || x[i] == '[') s.push(x[i]);
        else{
            if (s.empty()) return false;
            if (s.top() == '(' && x[i] == ')') s.pop();
            else if (s.top() == '{' && x[i] == '}') s.pop();
            else if (s.top() == '[' && x[i] == ']') s.pop();
            else return false;
        }
    }
    if(s.empty()) return true;
    return false;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
