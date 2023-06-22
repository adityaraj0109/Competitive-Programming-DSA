#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

TreeNode * solution(vector<int> &postorder, vector<int> &inorder,unordered_map<int,int> &m, int &index, int inorderstart, int inorderend){
    if(index<0 || inorderstart>inorderend){
        return NULL;
    }
    int element=postorder[index--];
    TreeNode *node=new TreeNode(element);
    int position=m[element];
    node->right=solution(postorder,inorder,m,index,position+1,inorderend);
    node->left=solution(postorder,inorder,m,index,inorderstart,position-1);
    return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int>& postorder)
{
    unordered_map<int,int>m;
    for(int i=0;i<inorder.size();i++){
        m[inorder[i]]=i;
    }
    int index=postorder.size()-1;
    int inorderstart=0;
    int inorderend=inorder.size()-1;
    TreeNode* ans=solution(postorder,inorder,m,index,inorderstart,inorderend);
    return ans;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}
