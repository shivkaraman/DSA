
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

void LLReverseTraversal(Node **tail){
    Node *current = *tail;
    while(current != NULL){
        cout<<current->data<<" ";
        current = current->prev;
    } 
    cout<<endl;
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

    cout<<"Reverse Linked List : ";
    LLReverseTraversal(&fourth);
    return 0;
}