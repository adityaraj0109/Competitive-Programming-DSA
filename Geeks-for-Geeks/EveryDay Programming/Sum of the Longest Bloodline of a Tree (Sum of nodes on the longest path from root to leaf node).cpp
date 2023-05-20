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


pair<int,int> solution(Node* root){
    if (root==NULL)
    {
        return {0,0};
    }
    pair<int,int>left=solution(root->left);
    pair<int,int>right=solution(root->right);
    if (left.first>right.first)
    {
        return {left.first+1,left.second+root->data};
    }
    return {right.first+1,right.second+root->data};
}

int sumOfLongRootToLeafPath(Node *root)
{
    pair<int,int>ans;
    ans=solution(root);
    return ans.second;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
