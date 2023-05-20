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

pair<int,int> diameterHeight(TreeNode *root){
    if (root==NULL)
    {
        return {0,0};
    }
    pair<int,int> left=diameterHeight(root->left);
    pair<int,int> right=diameterHeight(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;
    pair<int,int>ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}

int diameterOfBinaryTree(TreeNode *root)
{
    pair<int,int> ans=diameterHeight(root);
    return ans.first-1;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
