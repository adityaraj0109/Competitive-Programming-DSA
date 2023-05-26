#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void inorder(TreeNode* root, vector<int>& vec){
    if(root==NULL) return;
    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
}

bool findTarget(TreeNode *root, int k)
{
    vector<int>vec;
    inorder(root, vec);
    int i=0,j=vec.size()-1;
    while (i<j)
    {
        if(vec[i]+vec[j]==k) return true;
        else if(vec[i]+vec[j]>k) j--;
        else i++;
    }
    return false;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
