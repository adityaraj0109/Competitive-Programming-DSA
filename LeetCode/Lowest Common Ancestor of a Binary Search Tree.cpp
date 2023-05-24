#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root==NULL)
    {
        return NULL;
    }
    while (root!=NULL)
    {
        if (root->val<p->val && root->val<q->val)
        {
            root=root->right;
        }
        else if (root->val>p->val && root->val>q->val)
        {
            root=root->left;
        }
        else{
            return root;
        }
    }
    return root;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
