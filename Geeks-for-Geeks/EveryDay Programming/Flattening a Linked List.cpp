Node* middleNode(Node* head){
    Node* slow = head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        if (fast!=NULL)
        {
            fast=fast->next;
        }
    }
    return slow;
}

Node* merge(Node* left, Node* right){
    if (left==NULL)
    {
        return right;
    }
    if (right==NULL)
    {
        return left;
    }
    Node* merged=new Node(-1);
    Node* temp=merged;
    while (left!=NULL && right!=NULL)
    {
        if (left->data<= right->data)
        {
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else
        {
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while (left!=NULL)
    {
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while (right!=NULL)
    {
        temp->next=right;
        temp=right;
        right=right->next;
    }
    merged=merged->next;
    return merged;
}

Node* mergeSort(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* mid=middleNode(head);
    Node*left= head;
    Node* right=mid->next;
    mid->next=NULL;
    left=mergeSort(left);
    right=mergeSort(right);
    Node* result=merge(left,right);
    return result;
}

Node *flatten(Node *root)
{
    if (root == NULL)
    {
        return root;
    }
    Node* newNode=new Node(-1);
    Node* head=newNode;
    Node* curr=root;
    Node* temp=root;
    while (temp != NULL){
        curr=curr->next;
        while (temp!=NULL)
        {
            newNode->next=temp;
            newNode=temp;
            temp=temp->bottom;
        }
        temp=curr;
    }
    Node* tempp;
    head=head->next;
    Node* ans=mergeSort(head);
    tempp=ans;
    Node* answer=ans;
    Node*a=answer;
    while(tempp!=NULL){
        tempp=tempp->next;
        answer->bottom=tempp;
        answer=tempp;
    }
    return a;
}