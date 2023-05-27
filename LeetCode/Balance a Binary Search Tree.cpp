#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void inorder(TreeNode *root, vector<int> &vec)
{
    if (root == NULL)
        return;
    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
}

TreeNode* solution(vector<int> &vec, int start, int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    TreeNode* node= new TreeNode(vec[mid]);
    node->left=solution(vec,0,mid-1);
    node->right=solution(vec,mid+1,n-1);
    return node;
}

TreeNode *balanceBST(TreeNode *root)
{
    vector<int> vec;
    inorder(root, vec);
    int n=vec.size();
    return solution(vec,0,n-1,n);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
