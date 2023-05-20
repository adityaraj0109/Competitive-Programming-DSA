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

void leftTraversal(Node* root, vector<int> &ans){
    if(root == NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left != NULL){
        leftTraversal(root->left, ans);
    }
    else{
        leftTraversal(root->right,ans);
    }
}

void leafTraversal(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}

void rightTraversal(Node* root, vector<int> &ans){
    if(root == NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->right != NULL){
        rightTraversal(root->right, ans);
    }
    else{
        rightTraversal(root->left,ans);
    }
    ans.push_back(root->data);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);
    leftTraversal(root->left, ans);
    leafTraversal(root, ans);
    rightTraversal(root->right, ans);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
