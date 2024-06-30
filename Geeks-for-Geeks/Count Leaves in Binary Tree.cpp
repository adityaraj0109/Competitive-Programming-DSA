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

int countLeaves(Node* root)
{
    int count=0;
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    if(root->left!=NULL){
        count+=countLeaves(root->left);
    }
    if(root->right!=NULL){
        count+=countLeaves(root->right);
    }
    return count;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
