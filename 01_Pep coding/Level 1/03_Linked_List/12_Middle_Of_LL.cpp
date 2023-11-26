//Given a linked list , print the middle element of the linked list
//If the ll contains 2 middle elements, print the second

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
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

// Node* MiddleOfLL(Node **head){   //O(n) -->Bruteforce approach
//     Node *current = *head;
//     int count = 0;
//     while(current != NULL){
//         current = current->next;
//         count++;
//     }
//     current = *head;
//     for(int i=0;i<count/2;i++)
//         current = current->next;
//     return current;
// }

//Optimised --> Tortoise method --> We take two pointers (one called the slow tortoise and the other called as the fast tortoise)
// pointing to head. We traverse the slow tortoise by a distance of 1 through the linked list and fast tortoise by a distance of 2
//When the fast tortoise is at the last node, the slow tortoise would be at the middle node

Node* MiddleOfLL(Node **head){  //T=O(n) S=O(1)
    Node *fastPtr = *head;
    Node *slowPtr = *head;
    while(fastPtr && fastPtr->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    //If the first middle was to be found in case of even element
    // while(fastPtr->next && fastPtr->next->next){
    //     slowPtr = slowPtr->next;
    //     fastPtr = fastPtr->next->next;
    // }
    return slowPtr;
}

int main(){
    Node *head = new Node;
    head = LLInput();
    cout<<"Linked List : ";
    LLTraversal(&head);

    Node *Middle = MiddleOfLL(&head);
    cout<<"Middle of linked list : "<<Middle->data<<endl;
    return 0;
}