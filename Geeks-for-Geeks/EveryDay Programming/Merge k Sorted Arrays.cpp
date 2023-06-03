#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class node{
    public:
        int data;
        int i;
        int j;

        node(int data, int row, int col){
            this->data=data;
            i=row;
            j=col;
        }
};

class compare{
    public:
        bool operator()(node* a,node* b){
            return a->data>b->data;
        }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    vector<int>ans;
    priority_queue<node*,vector<node*>,compare>pq;
    for(int i=0;i<K;i++){
        node* temp=new node(arr[i][0],i,0);
        pq.push(temp);
    }   

    while (!pq.empty())
    {
        node* temp=pq.top();
        pq.pop();
        ans.push_back(temp->data);
        if (temp->j+1 < arr[0].size())
        {
            node* t=new node(arr[temp->i][temp->j+1],temp->i,temp->j+1);
            pq.push(t);
        }
    }
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
