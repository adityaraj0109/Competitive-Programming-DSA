#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head=new ListNode(0);
    ListNode* tail=head;
    int carry=0;
    while(l1 || l2 || carry){
        int val1=0;
        if(l1) val1=l1->val;
        int val2=0;
        if(l2) val2=l2->val;
        int sum=carry+val1+val2;
        carry=sum/10;
        tail->next= new ListNode(sum%10);
        tail=tail->next;
        if(l1) l1=l1->next;
        if(l2) l2=l2->next;
    }
    return head->next;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
