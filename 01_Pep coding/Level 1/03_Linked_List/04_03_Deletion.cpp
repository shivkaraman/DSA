
#include <iostream>
using namespace std;

class Node{
    public :
        int data;
        Node *prev;
        Node *next;
};

void LinkedListTraversal(Node **head){
    Node *current = *head;
    do{
        cout<<current->data<<" ";
        current = current->next;
    }while(current != *head);
    cout<<endl;
}

void DeleteFirst(Node ** head){
    if(*head == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    Node *current = *head;
    Node *temp = *head;
    while(current->next != *head){
        current = current->next;
    }
    *head = (*head)->next;
    (*head)->prev = current;
    current->next = *head;
    delete temp;
}

void DeleteLast(Node **head){
    if(*head == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    Node *current = *head;
    Node *temp;
    while(current->next != *head){
        temp = current;
        current = current->next;
    }
    temp->next = *head;
    (*head)->prev = temp;
    delete current;
}

void DeleteIdx(Node **head, int idx){
    if(*head == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    Node *current = *head;
    Node *temp = current->next;
    for(int i=0;i<idx-1 && temp->next != *head;i++){
        current = current->next;
        temp = temp->next;
    }
    if(temp->next == *head){
        cout<<"Idx not found"<<endl;
        return;
    }
    current->next = temp->next;
    (temp->next)->prev = current;
    delete temp;
}

void DeletingLinkedList(Node **head){
    if(*head == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    Node *current = *head;
    Node *temp;
    while(temp != *head){
        temp = current->next;
        delete current;
        current = temp;
    }
    *head = NULL;
}

int main(){
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;

    //Head node
    head->data = 10;
    head->prev = NULL;
    head->next = second;

    //Second node
    second->data = 20;
    second->prev = head;
    second->next = third;

    //Third node
    third->data = 30;
    third->prev = second;
    third->next = fourth;

    //Fourth node
    fourth->data = 40;
    fourth->prev = third;
    fourth->next = head;

    head->prev = fourth;
    
    cout<<"Linked List : ";
    LinkedListTraversal(&head);

    // //Deleting first node
    // DeleteFirst(&head);
    // cout<<"After deleting first node : ";
    // LinkedListTraversal(&head); 

    // //Deleting last
    // DeleteLast(&head);
    // cout<<"After deleting last node : ";
    // LinkedListTraversal(&head);

    // Deleting node at index
    // DeleteIdx(&head,2);
    // cout<<"After deleting Index : ";
    // LinkedListTraversal(&head);

    //Deleting Linked List
    DeletingLinkedList(&head);
    return 0;
}