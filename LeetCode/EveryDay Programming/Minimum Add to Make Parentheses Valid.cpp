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

int minAddToMakeValid(string s)
{
    stack<int>st;
    int count=0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '('){
            st.push(s[i]);
        }
        else{
            if (st.empty()){
                count++;
            }
            else{
                st.pop();
            }
        }
    }
    if (st.empty())
    {
        return count;
    }
    count+=st.size();
    return count;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
