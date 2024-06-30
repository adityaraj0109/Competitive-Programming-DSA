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

int compress(vector<char> &chars)
{
    int count=1,index=0,i=0;
    while (i<chars.size())
    {
        int j = i+1;
        count=1;
        while (j<chars.size() && chars[j]==chars[i])
        {
            count++;
            j++;
        }
        chars[index++]=chars[i];
        if (count>1)
        {
            string s=to_string(count);
            for (auto t : s)
            {
                chars[index++]=t;
            }
        }
        i=j;
    }
    return index;
}

int main()
{
    debugMode();
    vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int ans = compress(chars);
    cout <<endl<< ans << endl;
    return 0;
}
