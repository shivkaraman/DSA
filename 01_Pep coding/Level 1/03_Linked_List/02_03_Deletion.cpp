
#include <iostream>
using namespace std;

class Node{
    public :
        int data;
        Node *next;
};

void linkedListTraversal(Node *head){    //O(n) 
    Node *temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next; 
    }while(temp!=head);
    cout<<endl;
}

void DeleteFirst(Node **head){
    if(*head == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    Node *temp = *head;
    Node *current = *head;
    while(current->next != *head){
        current = current->next;
    }
    current->next = (*head)->next;
    *head = (*head)->next;
    delete temp; 
}

void DeleteLast(Node **head){
    if(*head == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    Node *current = *head;
    Node *temp = current->next;
    do{
        temp = temp->next;
        current = current->next;
    }while(temp->next != *head);
    current->next = *head;
    delete temp;
}

void DeleteLinkedList(Node **head){
    if(*head == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    Node *temp, *current = *head;
    while(temp != *head){
        temp = current->next;
        delete current;
        current = temp;
    }
    *head = NULL;
}

int main(){
    //Allocate memory for linked list in HEAP
    Node *head   = new Node;
    Node *second = new Node;
    Node *third  = new Node;
    Node *fourth = new Node;

    // Link first and second nodes
    head->data = 7;
    head->next = second;
 
    // Link second and third nodes
    second->data = 11;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
 
    //Pointing the next pointer of last node to head node 
    fourth->data = 66;
    fourth->next = head;
    linkedListTraversal(head);

    //Delete whole linked list
    DeleteLinkedList(&head);

    // Delete first node
    cout<<"After deleting first node : ";
    DeleteFirst(&head);
    linkedListTraversal(head);

    //Delete last node
    cout<<"After deleting last node : ";
    DeleteLast(&head);
    linkedListTraversal(head);

    return 0;
}  