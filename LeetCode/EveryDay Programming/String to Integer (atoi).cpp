#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool isdigit(char ch){
    if(ch>='0' && ch<='9') return true;
    return false;
}

int myAtoi(string s) {
    long ans=0;
    bool neg=false;
    int i=0;
    while (s[i]==' ') i++;
    for (; i < s.length(); i++) {
        if(s[i]=='+'){
            if(i!=0 && s[i-1]!=' ') break;
            continue;
        }
        if (s[i]=='-') {
            if(i!=0 && s[i-1]!=' ') break;
            neg = true;
            continue;
        }
        if(isdigit(s[i])){
            ans=ans*10+(s[i]-'0');
            if(neg && -1*ans<=INT_MIN) return INT_MIN;
            else if(ans>INT_MAX) return INT_MAX;
        }
        else break;
    }
    if(neg) return -1*ans;
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
