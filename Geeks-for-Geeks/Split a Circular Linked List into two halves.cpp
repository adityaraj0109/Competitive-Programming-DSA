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

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    if (head == NULL){
        *head1_ref = NULL;
        *head2_ref = NULL;
    }
    else if (head->next==head)
    {
        *head1_ref = head;
        *head2_ref = NULL;
    }
    else if (head->next->next==head)
    {
        *head1_ref = head;
        *head2_ref = head->next;
        (*head1_ref)->next=(*head1_ref);
        (*head2_ref)->next=(*head2_ref);
    }
    else
    {
        Node* slow=head;
        Node* fast=head->next;
        while (fast!=head && fast->next!=head)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        *head1_ref=head;
        *head2_ref=slow->next;
        Node* curr=slow->next;
        slow->next=*head1_ref;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=*head2_ref;
    }
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
