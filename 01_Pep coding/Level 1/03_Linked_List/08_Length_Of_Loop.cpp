//Given a linked list, find the length of loop (if exists)
// Check whether a given linked list is nul terminated or cyclic
// If yes move the fast pointer by a distance of 1 till it reaches the slow pointer again

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

int LoopLength(Node **head){  //T=O(n) S=O(1)
    Node *slowptr = *head;
    Node *fastptr = *head;
    int count = 0;
    bool looped = false;
    while(fastptr && slowptr && fastptr->next){
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if(slowptr == fastptr){
            looped = true;
            break;
        }
    }
    if(looped){
        do{
            fastptr = fastptr->next;
            count++;
        }while(fastptr != slowptr);
    }
    return count;
}

int main(){
    //Allocate memory for linked list in HEAP
    Node *head   = new Node;
    Node *second = new Node;
    Node *third  = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;

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
    fourth->next = fifth;
    
    //Looping
    fifth->data = 10;
    fifth->next = second;

    int len = LoopLength(&head);
    cout<<"Length of loop : "<<len<<endl;
    return 0;
}