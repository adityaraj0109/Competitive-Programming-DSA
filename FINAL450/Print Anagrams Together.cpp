#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<vector<string> > Anagrams(vector<string>& string_list) {
    map<string,vector<string>>m;
    for (int i = 0; i < string_list.size(); i++)
    {
        string str=string_list[i];
        sort(str.begin(),str.end());
        m[str].push_back(string_list[i]);
    }
    vector<vector<string>>ans;
    for(auto it:m){
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
