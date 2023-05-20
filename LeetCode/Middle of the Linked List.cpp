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

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head, *fast = head->next;
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    else if (fast->next==NULL)
    {
        return fast;
    }
    while (fast!=NULL){
        slow = slow->next;
        fast=fast->next;
        if (fast!=NULL){
            fast=fast->next;
        }
    }
    return slow;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
