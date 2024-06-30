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

ListNode *detectCycle(ListNode *head)
{
    if (head==NULL || head->next==NULL)
    {
        return NULL;
    }
    ListNode* slow=head;
    ListNode* fast=head;
    int flag=0;
    while(slow!=NULL && fast!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        if (slow==fast)
        {
            slow=head;
            flag=1;
            break;
        }
    }
    if(flag){
        while (slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
    return NULL;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
