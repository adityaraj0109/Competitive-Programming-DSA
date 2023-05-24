#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

Node* Predecessor(Node* root,int key){
    Node* pred=NULL;
    while(root!=NULL){
        if(root->key>=key){
            root=root->left;
        }
        else{
            pred=root;
            root=root->right;
        }
    }
    return pred;
}

Node* Successor(Node* root,int key){
    Node* suc=NULL;
    while(root!=NULL){
        if(root->key<=key){
            root=root->right;
        }
        else{
            suc=root;
            root=root->left;
        }
    }
    return suc;
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    pre=Predecessor(root,key);
    suc=Successor(root,key);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
