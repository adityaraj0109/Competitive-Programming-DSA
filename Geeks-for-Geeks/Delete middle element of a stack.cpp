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

//Approach 1
// void deleteMid(stack<int> &s, int sizeOfStack)
// {
//     stack<int>st;
//     int value=floor((sizeOfStack/2.0));
//     int count=0;
//     while (!s.empty())
//     {
//         if (count==value)
//         {
//             s.pop();
//             break;
//         }
//         st.push(s.top());
//         s.pop();
//         count++;
//     }
//     while (!st.empty())
//     {
//         s.push(st.top());
//         st.pop();
//     }
// }

//Approach 2
void solution(stack<int> &s,int value,int count){
    if (value==count)
    {
        s.pop();
        return;
    }

    int x=s.top();
    s.pop();
    solution(s,value,count+1);

    s.push(x);
}


void deleteMid(stack<int> &s, int sizeOfStack)
{
    int value=sizeOfStack/2;
    int count=0;
    solution(s,value,count);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
