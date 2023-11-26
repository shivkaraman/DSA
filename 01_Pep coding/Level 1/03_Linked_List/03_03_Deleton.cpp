
#include <iostream>
using namespace std;

class Node{
    public :
        int data;
        Node *prev;
        Node *next;
};

void LLtraversal(Node **head){
    Node *current = *head;
    while(current != NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

void DeleteFirst(Node **head){
    Node *current = *head;
    if(*head == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    *head = (*head)->next;
    (*head)->prev = NULL;
    delete current;
}

void DeleteLast(Node **head){
    Node *current = *head;
    Node *temp ;
    if(*head == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    while(current->next != NULL){
        temp = current;
        current = current->next;
    }
    temp->next = NULL;
    delete current;
}   

void DeleteAtIdx(Node **head, int idx){
    Node *current = *head;
    Node *temp = current->next;
    if(*head == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    for(int i=0; i<idx-1 && temp->next != NULL; i++){
        temp = temp->next;
        current = current->next;
    }
    if(temp->next == NULL){
        cout<<"Idx not found"<<endl;
        return;
    }
    current->next = temp->next;  
    (temp->next)->prev = current;
}

void DeleteLL(Node **head){
    Node *current = *head;
    Node *temp = current;
    while(current = NULL){
        temp = temp->next;
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
    fourth->next = NULL;
    
    cout<<"Linked List : ";
    LLtraversal(&head);

    //Delete first node
    // DeleteFirst(&head);
    // cout<<"After deleting first node : ";
    // LLtraversal(&head);

    // //Delete last node
    // DeleteLast(&head);
    // cout<<"After deleting last node : ";
    // LLtraversal(&head);

    // //Deleting at index
    // DeleteAtIdx(&head, 2);
    // cout<<"After deleting at idx 2 : ";
    // LLtraversal(&head); 

    //Delete Linked List
    DeleteLL(&head);
    return 0;
}