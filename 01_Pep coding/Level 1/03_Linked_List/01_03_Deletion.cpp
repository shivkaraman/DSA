
#include <iostream>
using namespace std;

class Node{
    public :
        int data;
        Node *next;
};

void linkedListTraversal(Node *ptr){    //O(n) 
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next; 
    }
    cout<<endl;
}

Node* DeleteFirst(Node *head){
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

void DeleteLast(Node *ptr){
    Node *temp;
    while(ptr->next!=NULL){
        temp = ptr;
        ptr = ptr->next;
    }
    //Now temp is the pointer pointing to last but 1 node
    temp->next = NULL;
    delete ptr;
}

void DeleteAtIdx(Node *ptr, int idx){
    Node *temp=ptr->next;
    for(int i=0;i<idx-1;i++){
        ptr = ptr->next;
        temp = temp->next;
    }
    //Now temp is the pointer pointing to node which is to be deleted
    ptr->next = temp->next;
    delete temp;
}

void DeleteByValue(Node *ptr, int value){
    Node *temp = ptr->next;
    while(temp->data != value && temp->next != NULL){
        ptr = ptr->next;
        temp = temp->next;
    }
    //Now temp points to node containing value
     ptr->next = temp->next;
    delete temp;
}

void DeleteLinkedList(Node **head){
    Node *temp, *current = *head;
    while(current != NULL){
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
    fourth->next = NULL;
    cout<<"Initial Linked List : ";
    linkedListTraversal(head);

    // // Deletion at first
    // head = DeleteFirst(head);
    // cout<<"After deletion at first : ";
    // linkedListTraversal(head);

    // //Deletion at last
    // DeleteLast(head);
    // cout<<"After deletion at first : ";
    // linkedListTraversal(head);

    //Deletion at Index
    DeleteAtIdx(head,1);
    cout<<"After deletion at idx 1 : ";
    linkedListTraversal(head);

    // //Deleton by value
    // DeleteByValue(head, 66);
    // cout<<"After deleting 11 : ";
    // linkedListTraversal(head);

    //Delete Linked List
    DeleteLinkedList(&head);
    return 0;
}