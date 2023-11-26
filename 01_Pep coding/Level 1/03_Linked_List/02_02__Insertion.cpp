
#include <iostream>
using namespace std;

class Node{
    public :
        int data;
        Node *next;
};

void linkedListTraversal(Node *head){    //O(n) 
    Node *current = head;
    do{
        cout<<current->data<<" ";
        current = current->next; 
    }while(current!=head);
    cout<<endl;
}

void InsertAtFirst(Node **head, int data){ //O(n)
    Node *newNode = new Node;
    Node *current = *head;
    newNode->data = data;
    newNode->next = newNode;
    while(current->next != *head){
        current = current->next;
    }
    if(*head == NULL)
        *head = newNode;
    else{
        newNode->next = *head;
        current->next = newNode;
        *head = newNode;
    }
}

 void InsertAtEnd(Node **head, int data){ //O(n)
    Node *newNode = new Node;
    Node *current = *head;
    newNode->data = data;
    newNode->next = newNode;
    while(current->next != *head){
        current = current->next;
    }
    if(head == NULL)
        *head = newNode;
    else{
        current->next = newNode;
        newNode->next = *head;
    }
    return;
}

void DeleteLinkedList(Node **head){
    if(*head == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    Node *temp, *current = *head;
    while(current != *head){
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
 
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = head;
    cout<<"Initial Linked List : ";
    linkedListTraversal(head);

    //Insert at first
    InsertAtFirst(&head, 10);
    cout<<"After insertion at first : ";
    linkedListTraversal(head);

    //Insert at end
    InsertAtEnd(&head, 98);
    cout<<"After insertion at end : ";
    linkedListTraversal(head);

    return 0;
}