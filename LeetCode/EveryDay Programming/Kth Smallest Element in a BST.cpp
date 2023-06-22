int solution(TreeNode *root, int k){
    int count=0;
    int ans;
    TreeNode* curr,*prev;
    curr=root;
    while (curr!=NULL)
    {
        if (curr->left==NULL)
        {
            count++;
            if (count==k){
                ans= curr->val;
            }
            curr=curr->right;
        }
        else{
            prev=curr->left;
            while (prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }
            if (prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                count++;
                if (count==k){
                    ans= curr->val;
                }
                curr=curr->right;
            }
        }
    }
    return ans;
}

int kthSmallest(TreeNode *root, int k)
{
    return solution(root,k);
}