//Reverse a singly linked list 

#include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node *next;
};

Node* LLInput(){
    Node *head = new Node;
    head = NULL;
    Node *prev = NULL;
    int choice;
    do{
        Node *newNode = new Node;
        cin>>newNode->data;
        newNode->next = NULL;
        if(head == NULL)
            head = newNode;
        else    
            prev->next = newNode;
        prev = newNode;
        cin>>choice;
    }while(choice != 0);
    return head;
}

void LLTraversal(Node **head){
    Node *current = *head;
    while(current != NULL){
        cout<<current->data<<"->";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}

void Reverse(Node **head){      //Iterative --> T=O(n) S=O(1)
    Node *prev = NULL;
    Node *current = *head;
    Node *next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main(){
    Node *head = new Node;
    head = LLInput();
    cout<<"Linked List : ";
    LLTraversal(&head);

    cout<<"Reversed Linked List : ";
    Reverse(&head);
    LLTraversal(&head);
    return 0;
}