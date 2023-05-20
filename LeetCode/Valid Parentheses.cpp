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

bool isValid(string s)
{
    stack<char>st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else{
            if (st.empty()){
                return false;
            }
            else if (s[i] == ')' && st.top() == '('){
                st.pop();
            }
            else if (s[i] == '}' && st.top() == '{'){
                st.pop();
            }
            else if (s[i] == ']' && st.top() == '['){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }
    return true;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
