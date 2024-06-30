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

bool hasCycle(ListNode *head)
    {
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while (slow!=NULL && fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
            if (fast!=NULL)
            {
                fast=fast->next;
            }
            if (slow==fast)
            {
                return true;
            }
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
