//Split the circular linked list into two halves

#include <iostream>
using namespace std;

class Node{
    public :
        int data;
        Node* next;
};

Node* CircularLL_Input(){
    Node *head;
    Node *prev = NULL;
    int choice;
    do{
        Node *newNode = new Node;
        newNode->next = NULL;
        cin>>newNode->data;
        if(prev == NULL){
            head = newNode;
        }
        else{
            prev->next = newNode;
        }
        prev = newNode;
        cin>>choice;
    }while(choice);
    prev->next = head;
    return head;
}

void LLTraversal(Node *head){
    Node *current = head;
    do{
        cout<<current->data<<"->";
        current = current->next;
    }while(current != head);
    cout<<"head"<<endl;
}

Node* splitLL(Node *head1, Node *head2){
    Node *slowPtr = head1;
    Node *fastPtr = head1;
    while(fastPtr->next != head1 && fastPtr->next->next != head1){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    if(fastPtr->next->next == head1){
        fastPtr = fastPtr->next;
    }
    fastPtr->next = slowPtr->next;
    head2 = slowPtr->next;
    slowPtr->next = head1;
    return head2;
}

int main(){
    Node *head = new Node;
    head = CircularLL_Input();
    cout<<"Circular Linked List : ";
    LLTraversal(head);

    Node *head2 = NULL;
    head2 = splitLL(head, head2);
    cout<<"Part 1 : ";
    LLTraversal(head);

    cout<<"Part 2 : ";
    LLTraversal(head2);
    return 0;
}