#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int solution(Node *root, int k){
    int count=0;
    if (root==NULL)
    {
        return -1;
    }
    Node* curr,*prev;
    curr=root;
    while (curr!=NULL)
    {
        if (curr->left==NULL)
        {
            count++;
            if (count==k){
                return curr->data;
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
                    return curr->data;
                }
                curr=curr->right;
            }
        }
    }
    return -1;
}

int KthSmallestElement(Node *root, int K) {
    return solution(root,K);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
