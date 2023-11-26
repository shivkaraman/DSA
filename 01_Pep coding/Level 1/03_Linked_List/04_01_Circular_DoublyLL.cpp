
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

    return 0;
}