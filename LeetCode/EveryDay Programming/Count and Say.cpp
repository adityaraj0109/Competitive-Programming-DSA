#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string solution(int n){
    if(n==1) return "1";
    string str=solution(n-1);
    string ans="";
    int count=1;
    for (int i = 0; i < str.size()-1; i++)
    {
        if(str[i]==str[i+1]){
            count++;
        }
        else{
            ans+=to_string(count)+str[i];
            count=1;
        }
    }
    ans+=to_string(count)+str[str.size()-1];
    return ans;
}

string countAndSay(int n)
{
    return solution(n);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<countAndSay(30);
    return 0;
}
