#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void inorder(Node* root,vector<int>&ans){
    if(root==NULL) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

vector<int> merge(Node *root1, Node *root2)
{
    vector<int>vec1;inorder(root1,vec1);
    vector<int>vec2;inorder(root2,vec2);
    vector<int>ans;
    int i=0,j=0;
    while(i<vec1.size() && j<vec2.size()){
        if(vec1[i]<vec2[j]){
            ans.push_back(vec1[i]);
            i++;
        }
        else{
            ans.push_back(vec2[j]);
            j++;
        }
    }
    while(i<vec1.size()){
        ans.push_back(vec1[i]);
        i++;
    }
    while(j<vec2.size()){
        ans.push_back(vec2[j]);
        j++;
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
