#include <bits/stdc++.h>
using namespace std;

string removeChars(string string1, string string2)
{
    string str;
    char ch;
    for (int i = 0; i < string2.size(); i++)
    {
        ch=char(string2[i]);
        string1.erase(remove(string1.begin(), string1.end(), ch),string1.end());
        str=string1;
    }
    return str;
}
int main()
{
    string str1 = "coco is a cat";
    string str2 = "iso";
    string s = removeChars(str1, str2);
    cout<<s;
    return 0;
}