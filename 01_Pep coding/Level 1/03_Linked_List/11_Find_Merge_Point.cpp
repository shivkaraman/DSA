/*
Suppose there are two singly linked lists intersecting at some point and becomes single linked list. The head of both linked lists
are known , find the intersecting point.

              a -> b -> c -
                            \_ p _ q _ r _ NULL 
                            /
    x -> y -> z -> l -> m -
*/

#include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node *next;
};

void LLTraversal(Node **head){
    Node *current = *head;
    while(current != NULL){
        cout<<current->data<<"->";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}

Node* MergePoint(Node *head1, Node *head2){
    Node *h1 = head1;
    Node *h2 = head2;
    int l1 = 0, l2 = 0;
    while(h1 != NULL){ 
        h1 = h1->next;
        l1++;
    }
    while(h2 != NULL){
        h2 = h2->next;
        l2++;
    }
    //Assign longer LL to h1
    if(l1>l2){
        h1 = head1;
        h2 = head2;
    }
    else{
        h1 = head2;
        h2 = head1;
    }
    //Find the difference of length and make 'diff' no of steps in longer ll
    for(int i=0; i<abs(l1-l2); i++){
        h1 = h1->next;
    }
    while(h1 != NULL && h2 != NULL){
        if(h1 == h2)
            return h1;

        h1 = h1->next;
        h2 = h2->next;
    }
    return NULL;
}

int main(){
    Node* newNode;
  
    //Head 1
    Node* head1 = new Node();
    head1->data = 10;
    
    //Head 2
    Node* head2 = new Node();
    head2->data = 3;
  
    //Second of head 2
    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;
  
    //Third of head 2
    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;
  
    //Second of head1
    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;

    //Third of head 1 and merge point
    newNode = new Node();
    newNode->data = 25;
    head1->next->next = newNode;
    head2->next->next->next = newNode;
  
    //Last Node of Linked List
    newNode = new Node();
    newNode->data = 30;
    head1->next->next->next = newNode;
  
    head1->next->next->next->next = NULL;
    
    Node *MergePt = MergePoint(head1, head2);
    cout<<"Merge Point : "<<MergePt->data<<endl;
    return 0;
}