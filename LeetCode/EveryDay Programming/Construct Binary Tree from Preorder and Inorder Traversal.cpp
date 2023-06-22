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

TreeNode * solution(vector<int> &preorder, vector<int> &inorder,unordered_map<int,int> &m, int &index, int inorderstart, int inorderend, int n){
    if(index>=n || inorderstart>inorderend){
        return NULL;
    }
    int element=preorder[index++];
    TreeNode *node=new TreeNode(element);
    int position=m[element];
    node->left=solution(preorder,inorder,m,index,inorderstart,position-1,n);
    node->right=solution(preorder,inorder,m,index,position+1,inorderend,n);
    return node;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int,int>m;
    for(int i=0;i<inorder.size();i++){
        m[inorder[i]]=i;
    }
    int index=0;
    int inorderstart=0;
    int inorderend=inorder.size()-1;
    int n=preorder.size();
    TreeNode* ans=solution(preorder,inorder,m,index,inorderstart,inorderend,n);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}
