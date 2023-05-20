#include <bits/stdc++.h>
#include <regex>
using namespace std;

string interpret(string command)
{
    string x="()";
    string y="(al)";
    int pos=command.find(x);
    while (pos!=string::npos)
    {
        command.replace(pos,x.size(),"o");
        pos=command.find(x,pos+1);
    }
    pos=command.find(y);
    while (pos!=string::npos)
    {
        command.replace(pos,y.size(),"al");
        pos=command.find(y,pos+1);
    }
    return command;
}
int main()
{
    string data = "G()()()()(al)";
    string x="()";
    string y="(al)";
    cout << data << endl;
    // findAndReplaceAll(data, "coco", "dd");
    // data=regex_replace(data,regex(x),y);
    data=regex_replace(data,regex(y),"al");
    cout<<data<<endl;
    cout << interpret(data) << endl;
    return 0;
}