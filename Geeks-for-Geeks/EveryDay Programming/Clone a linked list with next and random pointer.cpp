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

void insertAtTail(Node* &tail, int data)
{
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

//solution with O(n) time complexity and O(n) space complexity
Node *copyList1(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *clonehead = new Node(temp->data);
    Node *tail = clonehead;
    unordered_map<Node *, Node *> m;
    m[temp] = tail;
    temp = temp->next;
    while (temp != NULL)
    {
        insertAtTail(tail, temp->data);
        m[temp] = tail;
        temp = temp->next;
    }
    temp = head;
    Node *clonetemp = clonehead;
    while (temp != NULL)
    {
        clonetemp->arb = m[temp->arb];
        clonetemp = clonetemp->next;
        temp = temp->next;
    }
    return clonehead;
}

//solution with O(n) time complexity and O(1) space complexity
Node *copyList(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *clonehead = new Node(temp->data);
    Node *tail = clonehead;
    temp = temp->next;
    while (temp != NULL)
    {
        insertAtTail(tail, temp->data);
        temp = temp->next;
    }
    temp=head;
    Node* clonetemp=clonehead;
    while (temp!=NULL)
    {
        Node* next= temp->next;
        temp->next=clonetemp;
        temp=next;
        next=clonetemp->next;
        clonetemp->next=temp;
        clonetemp=next;
    }
    temp=head;
    clonetemp=temp->next;
    while (temp!=NULL){
        if(temp->arb!=NULL){
            clonetemp->arb=temp->arb->next;
        }
        temp=temp->next->next;
        if (temp!=NULL)
        {
            clonetemp=clonetemp->next->next;
        }
    }
    temp=head;
    clonetemp=clonehead;
    Node* next= temp->next->next;
    while (temp!=NULL){
        temp->next=next;
        temp=next;
        if (next!=NULL){
            next=next->next;
            clonetemp->next=next;
            clonetemp=next;
            next=next->next;
        }
    }
    clonetemp->next=NULL;
    return clonehead;
}



int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
