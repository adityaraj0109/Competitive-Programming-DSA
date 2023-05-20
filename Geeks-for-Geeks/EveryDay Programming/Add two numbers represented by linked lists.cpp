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

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next=NULL;
    }
};

void insertAtTail(Node* &tail,int data){
    Node *newNode = new Node(data);
    tail->next=newNode;
    tail = newNode;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node *addTwoLists(Node *first, Node *second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    Node *temp1 = reverseList(first);
    Node* head=temp1;
    Node* prev=NULL;
    Node *temp2 = reverseList(second);
    // print(temp1);
    // print(temp2);
    int carry = 0, value, sum;
    while (temp1 != NULL && temp2 != NULL)
    {
        sum = temp1->data + temp2->data + carry;
        value = sum % 10;
        carry = sum / 10;
        temp1->data = value;
        prev=temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
        // cout<<value<<" "<<carry<<endl;
    }
    if (temp1 == NULL && temp2 == NULL && carry != 0)
    {
        insertAtTail(prev,carry);
        head=reverseList(head);
        return head;
    }
    if (temp1 != NULL && carry == 0)
    {
        head=reverseList(head);
        return head;
    }
    if (temp2 != NULL && carry == 0)
    {
        prev->next= temp2;
        head=reverseList(head);
        return head;
    }
    while (temp1 != NULL)
    {
        sum = temp1->data + carry;
        value = sum % 10;
        carry = sum / 10;
        temp1->data = value;
        prev=temp1;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        sum = temp2->data + carry;
        value = sum % 10;
        carry = sum / 10;
        insertAtTail(prev,value);
        temp2 = temp2->next;
        // cout<<value<<" "<<carry<<endl;
    }
    if (temp1 == NULL && temp2 == NULL && carry != 0)
    {
        insertAtTail(prev,carry);
        head=reverseList(head);
        return head;
    }
    head=reverseList(head);
    // print(head);
    return head;
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *node1=new Node(1);
    Node *head1=node1;
    Node *first=node1;
    insertAtTail(first,7);
    insertAtTail(first,8);
    insertAtTail(first,3);
    insertAtTail(first,6);
    insertAtTail(first,9);
    insertAtTail(first,4);
    // print(head1);
    Node *node2=new Node(8);
    Node *second=node2;
    Node *head2=node2;
    insertAtTail(second,4);
    insertAtTail(second,8);
    insertAtTail(second,5);
    insertAtTail(second,7);
    insertAtTail(second,2);
    insertAtTail(second,3);
    insertAtTail(second,8);
    insertAtTail(second,3);
    // print(head2);
    Node*head=addTwoLists(head2,head1);
    print(head);
    return 0;
}
