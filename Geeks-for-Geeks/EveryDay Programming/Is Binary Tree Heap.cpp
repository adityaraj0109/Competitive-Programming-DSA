#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool isvaluegreater(struct Node *tree)
{
    if (tree->left == NULL && tree->right == NULL)
    {
        return true;
    }
    if (tree->right == NULL)
    {
        return tree->data > tree->left->data;
    }
    else
    {
        bool left = isvaluegreater(tree->left);
        bool right = isvaluegreater(tree->right);

        return (left && right && (tree->left->data < tree->data) && (tree->right->data < tree->data));
    }
}

bool iscomplete(struct Node *tree, int index, int totalNode)
{
    if (tree == NULL)
    {
        return true;
    }
    if (index >= totalNode)
    {
        return false;
    }
    else
    {
        bool left = iscomplete(tree->left, 2 * index + 1, totalNode);
        bool right = iscomplete(tree->right, 2 * index + 2, totalNode);

        return (left && right);
    }
}

int totalCount(struct Node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    int ans = 1 + totalCount(tree->left) + totalCount(tree->right);
    return ans;
}

bool isHeap(struct Node *tree)
{
    int index = 0;
    int totalNode = totalCount(tree);
    if (iscomplete(tree, index, totalNode) && isvaluegreater(tree))
    {
        return true;
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
