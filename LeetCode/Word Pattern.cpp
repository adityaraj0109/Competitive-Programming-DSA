#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;

bool wordPattern(string pattern, string s)
{
    vector<string>vec;
    vector<string>v;
    string temp="";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]==' ')
        {
            vec.push_back(temp);
            temp="";
        }
        else
        {
            temp=temp+s[i];
        }
    }
    vec.push_back(temp);
    if (vec.size()!=pattern.length())
    {
        return false;
    }
    unordered_map<char,string>m;
    unordered_set<string>sett;
    for (int i = 0; i <pattern.length() ; i++)
    {
        m.insert(make_pair(pattern[i],vec[i]));
        sett.insert(vec[i]);
        for (int j = i+1; j < pattern.length(); j++)
        {
            if (pattern[i]==pattern[j])
            {
                if (vec[i]!=vec[j])
                {
                    return false;
                }
            }
        }
    }
    if (sett.size()!=m.size())
    {
        return false;
    }
    return true;
}

int main()
{
    string pattern, s;
    pattern="aaa";
    s="aa aa aa aa";
    bool ans = wordPattern(pattern, s);
    cout << ans << endl;
    return 0;
}