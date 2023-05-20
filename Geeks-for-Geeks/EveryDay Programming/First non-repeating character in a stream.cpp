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

string FirstNonRepeating(string A)
{
    string str="";
    unordered_map<char,int>m;
    queue<char>q;
    for(int i=0;i<A.size();i++){
        m[A[i]]++;
        q.push(A[i]);
        while (!q.empty())
        {
            if (m[q.front()]>1)
            {
                q.pop();
            }
            else
            {
                str+=q.front();
                break;
            }
        }
        if (q.empty())
        {
            str+="#";
        }
    }
    return str;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
