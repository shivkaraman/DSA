//Check if the length of ll is even or odd

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

int LLlen(Node *head){
    while(head && head->next){
        head = head->next->next;
        if(head == NULL)
            return 0;
    }
    return 1;
}

int main(){
    Node *head = new Node;
    head = LLInput();
    cout<<"Linked List : ";
    LLTraversal(&head);

    cout<<"LL len is ";
    if(LLlen(head))
        cout<<"Odd"<<endl;
    else    
        cout<<"Even"<<endl;
    return 0;
}