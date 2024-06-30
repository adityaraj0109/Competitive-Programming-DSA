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

void removeLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    if (head->next == head)
    {
        head->next = NULL;
        return;
    }
    Node *slow = head;
    Node *fast = head;
    int flag = 0;
    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        if (slow == fast)
        {
            slow = head;
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        while (fast->next!=slow)
        {
            fast=fast->next;
        }
        fast->next=NULL;
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
