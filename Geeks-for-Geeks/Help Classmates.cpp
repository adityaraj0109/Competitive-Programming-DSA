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

vector<int> help_classmate(vector<int> arr, int n)
{
    vector<int> ans;
    stack<int>s;
    s.push(-1);
    for (int i = n-1; i >=0; i--)
    {
        while (s.top()>=arr[i])
        {
            s.pop();
        }
        ans.push_back(s.top());
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
