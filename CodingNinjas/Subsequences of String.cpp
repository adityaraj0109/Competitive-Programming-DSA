#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solution(vector<string> &ans, string &s,int index,string str){
    if(index==str.size()){
        if(s!="") ans.push_back(s);
        return;
    }
    solution(ans,s,index+1,str);
    s=s+str[index];
    solution(ans,s,index+1,str);
    s.pop_back();
}

vector<string> subsequences(string str)
{
    vector<string>ans;
    string s="";
    solution(ans,s,0,str);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < ; i++)
    {
        /* code */
    }
    return 0;
}
