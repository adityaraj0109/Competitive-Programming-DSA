#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

vector<int> NGE(vector<int>v){
    stack<int>st;
    vector<int>vec(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i]>v[st.top()])
        {
            vec[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        vec[st.top()]=-1;
        st.pop();
    }
    return vec;
}

int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    vector<int>v=NGE(vec);
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]==-1)
        {
            cout<<vec[i]<<" "<<-1<<endl;
        }
        else{
            cout<<vec[i]<<" "<<vec[v[i]]<<endl;
        }
    }
    return 0;
}