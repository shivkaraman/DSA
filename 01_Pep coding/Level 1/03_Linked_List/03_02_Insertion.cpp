
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

void InsertAtFirst(Node **head, int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL; 
    if(*head == NULL)
        *head = newNode;
    else{ 
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void InsertAtLast(Node **head, int data){
    Node *current = *head;
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    while(current->next != NULL){
        current = current->next;
    }
    newNode->prev = current;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    current->next = newNode;
}

void InsertAtIdx(Node **head, int idx, int data){
    Node *current = *head;
    Node *newNode = new Node;
    newNode->data = data;
    for(int i=0;i<idx-1;i++)
        current = current->next;
        
    newNode->prev = current;
    newNode->next = current->next;
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
    fourth->next = NULL;
    
    cout<<"Linked List : ";
    LLtraversal(&head);

    //Insertion at first
    InsertAtFirst(&head, 0);
    cout<<"After first insertion : ";
    LLtraversal(&head);

    //Insertion at last
    InsertAtLast(&head, 50);
    cout<<"After insertion at last : ";
    LLtraversal(&head);

    //Insertion at index
    InsertAtIdx(&head, 2, 15);
    cout<<"After insertion at Indez 2 : ";
    LLtraversal(&head);
    return 0;
}