#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solution(vector<string> &ans,string &s,int index,string str){
    if(index>=s.size()){
        if(str!="") ans.push_back(str);
        return;
    }
    solution(ans,s,index+1,str);
    str=str+s[index];
    solution(ans,s,index+1,str);
}

vector<string> AllPossibleStrings(string s)
{
    vector<string>ans;
    string str="";
    solution(ans,s,0,str);
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
