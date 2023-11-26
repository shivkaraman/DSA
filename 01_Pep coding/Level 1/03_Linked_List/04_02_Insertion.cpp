
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

void InsertAtFirst(Node **head, int data){
    Node *current = *head;
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    while(current->next != *head){
        current = current->next;
    }
    if(*head == NULL)
        *head = newNode;
    else{
        newNode->next = *head;
        current->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void InsertAtLast(Node **head, int data){
    Node *current = *head;
    Node *newNode = new Node;
    newNode->data = data;
    while(current->next != *head){
        current = current->next;
    }
    newNode->next = newNode;
    newNode->prev = newNode;
    if(*head == NULL)
        *head = newNode;
    else{
        newNode->next = *head;
        current->next = newNode;
        (*head)->prev = newNode;
    }
}

void InsertAtIdx(Node **head, int idx, int data){
    Node *current = *head;
    Node *newNode = new Node;
    newNode->data = data;
    for(int i=0;i<idx-1 && current->next != *head;i++){
        current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
    (newNode->next)->prev = newNode;
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

    //Insert at first
    InsertAtFirst(&head, 0);
    cout<<"After inertion at first : ";
    LinkedListTraversal(&head);

    //Insert at last
    InsertAtLast(&head, 50);
    cout<<"After inertion at last : ";
    LinkedListTraversal(&head);

    //Insert at index
    InsertAtIdx(&head, 2, 15);
    cout<<"After inertion at index : ";
    LinkedListTraversal(&head);

    
    return 0;
}