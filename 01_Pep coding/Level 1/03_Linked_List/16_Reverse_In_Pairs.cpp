//Reverse a singly linked list in pairs
// 1->2->3->4->NULL
// 2->1->4->3->NULL

#include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node *next;
};

Node* LLInput(){
    Node *head = NULL;
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

void ReverseInPair(Node **head){    //Iterative  T=O(N)  S=O(1)
    Node *current = *head;
    Node *temp = *head;
    Node *prev = NULL;
    
    *head = current->next;
    while(current && current->next){
        temp = current->next->next;
        current->next->next = current;
        if(prev){
            prev->next = current->next;
        }
        prev = current;
        current->next = temp;
        current = current->next;
    }
}

// Node* ReverseInPair(Node *head){    //Recursive  T=O(N) S=O(N)
//     if(head==NULL || head->next == NULL)
//         return head;
//     Node *temp, *current = head;
//     head = current->next;
//     temp = current->next->next;
//     current->next->next = current;
//     current->next = ReverseInPair(temp);
//     return head;
// }

int main(){
    Node *head = new Node; 
    head = LLInput();
    cout<<"Linked List : ";
    LLTraversal(&head);

    ReverseInPair(&head);
    cout<<"Linked List : ";
    LLTraversal(&head);
    return 0;
}