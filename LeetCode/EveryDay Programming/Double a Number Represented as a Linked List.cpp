#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

ListNode* rever(ListNode* head) {
    ListNode* p = NULL;
    ListNode* c = head;
    while (c != NULL) {
        ListNode* nextNode = c->next;
        c->next = p;
        p = c;
        c = nextNode;
    }
    return p;
}

ListNode* doubleIt(ListNode* head) {
    head = rever(head);
    ListNode* newnode = NULL;
    int car = 0;
    ListNode* c = head;
    while (c != NULL || car != 0) {
        int sum = car;
        if (c != NULL) {
            sum += c->val * 2;
            c = c->next;
        }
        car = sum / 10;
        if (newnode == NULL) {
            newnode = new ListNode(sum % 10);
        } else {
            newnode = new ListNode(sum % 10, newnode);
        }
    }
    return newnode;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
