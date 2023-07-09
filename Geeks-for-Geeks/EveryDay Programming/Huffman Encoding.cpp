#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data=data;
            left=NULL;
            right=NULL;
        }
};

class Compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data>b->data;  //array ka ulta hota hai heap me
        }
};

void traversal(Node* root, vector<string> &ans, string code){
    if(root->left==NULL && root->right==NULL){
        ans.push_back(code);
        return;
    }
    traversal(root->left,ans,code+"0");
    traversal(root->right,ans,code+"1");
}

vector<string> huffmanCodes(string S, vector<int> f, int N)
{
    priority_queue<Node*,vector<Node*>,Compare>pq;
    vector<string>ans;
    for(int i=0;i<N;i++){
        Node* temp=new Node(f[i]);
        pq.push(temp);
    }
    while(pq.size()>1){
        Node* a=pq.top();
        pq.pop();
        Node* b=pq.top();
        pq.pop();
        Node* c=new Node(a->data+b->data);
        c->left=a;
        c->right=b;
        pq.push(c);
    }
    Node* root=pq.top();
    string code="";
    traversal(root,ans,code);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
