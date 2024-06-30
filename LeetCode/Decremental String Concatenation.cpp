#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int minimizeConcatenatedLength(vector<string> &words)
{
    if(words.size()==1){
        return words[0].length();
    }
    vector<int>visited(words.size(),0);
    int i=1;
    string str=words[0];
    while (i<words.size())
    {
        for (int j = i; j < words.size(); j++)
        {
            if(words[j][0]==str[str.size()-1]){
                visited[j]=1;
                str=words[j]+str.substr(1);
            }
            else if(str[0]==words[j][words[j].size()-1])
        }
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
