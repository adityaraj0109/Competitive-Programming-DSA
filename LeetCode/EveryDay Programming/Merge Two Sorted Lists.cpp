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

ListNode* solution(ListNode *list1, ListNode *list2){
    if(list1->next==NULL){
        list1->next=list2;
        return list1;
    }
    ListNode* curr1=list1;
    ListNode* curr2=list2;
    ListNode* forward1=list1->next;
    ListNode* forward2;
    while (forward1!=NULL && curr2!=NULL)
    {
        if (curr1->val<= curr2->val && forward1->val>=curr2->val)
        {
            forward2=curr2->next;
            curr1->next=curr2;
            curr2->next=forward1;
            curr1=curr2;
            curr2=forward2;
        }
        else{
            curr1=curr1->next;
            forward1=forward1->next;
        }
    }
    if(curr2!=NULL){
        curr1->next=curr2;
    }
    return list1;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if(list1 == NULL){
        return list2;
    }
    if (list2== NULL)
    {
        return list1;
    }
    if (list1->val < list2->val)
    {
        return solution(list1,list2);
    }
    return solution(list2,list1);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
