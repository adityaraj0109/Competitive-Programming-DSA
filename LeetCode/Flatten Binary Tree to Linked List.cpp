#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void flatten(TreeNode *root)
{
    if (root==NULL)
    {
        return;
    }
    TreeNode *curr,*prev;
    curr=root;
    while (curr!=NULL)
    {
        if (curr->left==NULL)
        {
            curr=curr->right;
        }
        else{
            prev=curr->left;
            while (prev->right!=NULL && prev->right!=curr)
            {
                prev=prev->right;
            }

            if (prev->right==NULL)
            {
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
                curr=curr->right->right;
            }
        }
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
