#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> search(string pat, string txt)
{
    vector<int>ans;
    int i=0,index;
    while(i < txt.size())
    {
        if(txt[i]==pat[0]){
            index=i+1;
            for (int j = 1; j < pat.size(); j++)
            {
                if(index<txt.size() && txt[index]==pat[j]){
                    index++;
                }
                else{
                    i=index;
                    break;
                }
            }
            if(index-i==pat.size()){
                ans.push_back(i+1);
                i=i+1;
            }
        }
        else i++;
    }
    if(ans.size()==0) return {-1};
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
