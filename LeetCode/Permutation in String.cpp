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

bool check(vector<int>v1,vector<int>v2){
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i]!=v2[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    if (s1.length()>s2.length())
    {
        return false;
    }
    int size=s1.length();
    vector<int>v1(26);
    vector<int>v2(26);
    for (int i = 0; i < size; i++)
    {
        v1[(s1[i]-'a')]++;
    }
    for (int i = 0; i < size; i++)
    {
        v2[(s2[i]-'a')]++;
    }
    if(check(v1,v2)){
        return true;
    }
    int j=0;
    for (int i = size; i < s2.length(); i++)
    {
        v2[(s2[j]-'a')]--;
        v2[(s2[i]-'a')]++;
        if(check(v1,v2)){
            return true;
        }
        j++;
    }
    return false;
}

int main()
{
    debugMode();
    string s1 = "ab", s2 = "eidboaoo";
    bool ans = checkInclusion(s1, s2);
    cout << ans << endl;
    return 0;
}
