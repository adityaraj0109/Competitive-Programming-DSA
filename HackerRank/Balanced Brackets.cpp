#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

string isBalanced(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ']' || s[i] == ')' || s[i] == '}')
        {
            if (st.empty())
            {
                return "NO";
            }
            char top = st.top();
            if ((s[i] == ']' && top == '[') || (s[i] == '}' && top == '{') || (s[i] == ')' && top == '('))
            {
                st.pop();
            }
            else
            {
                return "NO";
            }
        }
    }
    if (st.empty())
    {
        return "YES";
    }
    return "NO";
}

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    debugMode();
    int n;
    cin >> n;
    string s, str;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        str = isBalanced(s);
        cout << str << endl;
    }
    return 0;
}
