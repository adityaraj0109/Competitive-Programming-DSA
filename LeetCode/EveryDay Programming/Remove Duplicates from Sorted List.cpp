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

ListNode *deleteDuplicates(ListNode *head)
{
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    ListNode* prev=head;
    ListNode* curr=head->next;
    ListNode* temp;
    while (curr!=NULL){
        if(prev->val==curr->val){
            prev->next=curr->next;
            temp=curr;
            curr=curr->next;
            temp->next=NULL;
            delete temp;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
