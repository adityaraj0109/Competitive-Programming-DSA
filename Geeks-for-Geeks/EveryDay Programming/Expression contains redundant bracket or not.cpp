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

int checkRedundancy(string s)
{
    stack<char>st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        {
            st.push(s[i]);
        }
        if (s[i]==')' && st.top()=='(')
        {
            return 1;
        }
        if (s[i]==')'){
            while (st.top()!='(' && !st.empty())
            {
                st.pop();
            }
            st.pop();
        }
    }
    if (st.empty()){
        return 0;
    }
    return 1;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
