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

void solution(vector<string>&ans,int index,string digits,string &str,vector<string>temp){
    if (index==digits.length())
    {
        ans.push_back(str);
        return;
    }
    int digit=digits[index]-'0';
    string value=temp[digit];
    for (int i = 0; i < value.size(); i++)
    {
        str.push_back(value[i]);
        solution(ans,index+1,digits,str,temp);
        str.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string>ans;
    if (digits.size()==0)
    {
        return ans;
    }
    string str="";
    vector<string>temp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solution(ans,0,digits,str,temp);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
