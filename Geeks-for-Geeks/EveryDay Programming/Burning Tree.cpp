#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

Node* findTargetandMappingParent(Node* &root, int target,unordered_map<Node*,Node*> &m ){
    if(root==NULL){
        return NULL;
    }
    Node* ans=NULL;
    queue<Node*>q;
    q.push(root);
    m[root]=NULL;
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp->data==target){
            ans=temp;
        }
        if(temp->left){
            m[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right){
            m[temp->right]=temp;
            q.push(temp->right);
        }
    }
    return ans;
}

int solution(Node* &targetNode,unordered_map<Node*,Node*> &m){
    int ans=0;
    if(targetNode==NULL){
        return ans;
    }
    queue<Node*>q;
    unordered_map<Node*,bool>visited;
    q.push(targetNode);
    visited[targetNode]=true;
    while(!q.empty()){
        int size=q.size();
        int flag=0;
        for (int i = 0; i < size; i++)
        {
            Node* temp=q.front();
            q.pop();
            if(temp->left && visited[temp->left]!=true){
                q.push(temp->left);
                visited[temp->left]=true;
                flag=1;
            }
            if(temp->right && visited[temp->right]!=true){
                q.push(temp->right);
                visited[temp->right]=true;
                flag=1;
            }
            if(m[temp] && visited[m[temp]]!=true){
                q.push(m[temp]);
                visited[m[temp]]=true;
                flag=1;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    return ans;
}

int minTime(Node *root, int target)
{
    unordered_map<Node*,Node*>m;
    Node* targetNode=findTargetandMappingParent(root,target,m);
    int ans=solution(targetNode,m);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
