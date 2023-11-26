// Delte kth node from last in a linked lilst

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

void DeleteLastKthNode(Node **head, int k){ // T=O(n)  S=O(1)
    Node *current = *head;
    int count = 0;
    while(current != NULL){
        current = current->next;
        count++;
    }
    current = *head;
    Node *prev = NULL;
    for(int i = 0; i<count-k; i++){
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    delete current;
}

int main(){
    Node *head = new Node;
    head = LLInput();
    cout<<"Linked List : ";
    LLTraversal(&head);

    int k;
    cin>>k;
    DeleteLastKthNode(&head, k);

    cout<<"After deletion kth node from last : ";
    LLTraversal(&head);
    return 0;
}  