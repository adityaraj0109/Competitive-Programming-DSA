#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solution(string S,vector<string> &ans, int index){
    if(index==S.size()){
        ans.push_back(S);
        return;
    }
    for(int i=index;i<S.size();i++){
        if(S[index]==S[i] && i!=index){
            continue;
        }
        swap(S[index],S[i]);
        solution(S,ans,index+1);
    }
}

vector<string> find_permutation(string S)
{
    vector<string>ans;
    sort(S.begin(),S.end());
    solution(S,ans,0);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
